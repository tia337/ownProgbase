#include <list.h>
#include <JsonLoader.h>
#include <jansson.h>
#include <string.h>

struct Clients{
    char name[20];
};

struct TaxiDriver{
    char name[40];
    int age;
    float salary;
    List * clients; 
};





TaxiDriver * TaxiDriver_new(char * name, int age, float salary, List * clients){
    TaxiDriver * self = malloc(sizeof(TaxiDriver));
    strcpy(self->name, name);
    self->age = age;
    self->salary = salary;
    self->clients = clients;
    return self;
}

void TaxiDriver_free(TaxiDriver ** selfPtr){
    free(*selfPtr);
    *selfPtr = NULL;
}

List * TaxiDriver_getClients(const TaxiDriver * self){
    return self->clients;
}

void JsonLoader_saveToString(char * str, const TaxiDriver * driver){
    json_t * json = json_object();
	json_object_set_new(json, "name", json_string(driver->name));
	json_object_set_new(json, "age", json_integer(driver->age));
	json_object_set_new(json, "salary", json_real(driver->salary));
    json_t * clients = json_array();
    List * list = TaxiDriver_getClients(driver);
    int len = List_count(list);
    for(int i = 0; i < len; i++){
        Clients * cl = List_get(list, i);
        json_t * clientObj = json_object();
        json_object_set_new(clientObj, "name", json_string(cl->name));
        json_array_append(clients, clientObj);
        json_decref(clientObj);
    }
    json_object_set_new(json, "clients", clients);

	// create JSON document string
	char * jsonString = json_dumps(json, JSON_INDENT(2) | JSON_PRESERVE_ORDER);
    strcpy(str, jsonString);
	free(jsonString);
    // decrease reference count (free's memory when count is 0')
    json_decref(json);
}

void JsonLoader_loadFromString(TaxiDriver * driver, const char * jsonString){
    json_error_t err;
	json_t * jsonObj = json_loads(jsonString, 0, &err);
    
    strcpy(driver->name, (char*)json_string_value(json_object_get(jsonObj, "name")));
    driver->age = json_integer_value(json_object_get(jsonObj, "age"));
	driver->salary = json_real_value(json_object_get(jsonObj, "salary"));
    
    List * clients = List_new();
    json_t * jsonArr = json_object_get(jsonObj, "clients");
	int index = 0;
    json_t * value = NULL;
	json_array_foreach(jsonArr, index, value) {
        Clients * client = malloc(sizeof(Clients));
        strcpy(client->name, json_string_value(json_object_get(value, "name")));
        List_addLast(clients, client);
	}
    driver->clients = clients;
    json_decref(jsonObj);
}