#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <list.h>
#include <events.h>
#include <pbconsole.h>
#include <string.h>
/* custom constant event type ids*/
enum {
	CustomEventTypeId
};

enum {
	input,
	output
};

typedef struct Str Str;
struct Str{
	char string[50];
	int cond;
};


void structGet(Str * self);

/* event handler functions prototypes */
void KeyInputHandler_update(EventHandler * self, Event * event);
void CustomHandler_update(EventHandler * self, Event * event);

int main(void) {	
	Str * ptr = malloc(sizeof(struct Str));
	ptr->string[0] = '\0';
	ptr->cond = 0;
	// startup event system
	EventSystem_init();

	// add event handlers
	printf("to start press enter\n");
	EventSystem_addHandler(EventHandler_new(ptr, free, CustomHandler_update));
	EventSystem_addHandler(EventHandler_new(NULL, NULL, KeyInputHandler_update));
	
	
	// start infinite event loop
	EventSystem_loop();
	// cleanup event system
	EventSystem_cleanup();
	return 0;
}

/* event handlers functions implementations */

void KeyInputHandler_update(EventHandler * self, Event * event) {
	if (conIsKeyDown()) {  // non-blocking key input check
		char * keyCode = malloc(sizeof(char));

		*keyCode = getchar();
		if (*keyCode == 27) {  // Escape key code
			free(keyCode);
			EventSystem_exit();	
		} else if(*keyCode == 10) {
			EventSystem_raiseEvent(Event_new(self, CustomEventTypeId, keyCode, free));
		}
	}
}
void CustomHandler_update(EventHandler * self, Event * event) {
	switch(event->type){
		case CustomEventTypeId:{
			char * keyCode= event->data;
			if (*keyCode == 10) {  
				if (((Str *)self->data)->cond == input) {
					printf("Output:\n");
					((Str *)self->data)->cond = output;
					puts(((Str *)self->data)->string);
					puts("");
				}
				if (((Str *)self->data)->cond == output) {
					((Str *)self->data)->cond = input;
					printf("Input:\n");
					structGet(self->data);
				}
			}
			
		}
	}
}


void structGet(Str * self){
	fgets(self->string, 20, stdin);
	//  self->string[0] = '\0';
	//  self->string[strlen(self->string) - 1] = '\0';
	//  scanf("%s/n",self->string);
}
