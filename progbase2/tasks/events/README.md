# Event system

A simple event system written in C language to perform basic Event-Driven Programming.

## Updates

Added new API function `EventSystem_exit()` to break EventLoop easily.

## Main types

### Event

Event is an object of some specified type that holds a reference to some type-specific data and data DestructorFunction. Each Event also has a pointer to the EventHandler that raises it.

### EventHandler

EventHandler is an object that that holds a reference to some specific data (a handler instance) and data DestructorFunction. Each EventHandler also defines EventHandlerFunction that is used to handle some raised Event for EventHandler that is registered in EventSystem

## EventSystem

EventSystem is a static module that encapsulates implementation and logic of event system.

EventSystem contains a list of EventHanlers, an EventQueue of Events and runs infinite event loop to handle events from queue with event handlers.

Every EventHandler can statically add new EventHandler to EventSystem or remove existing.

Every EventHandler can raise new Event when handling some Event.

The event loop raises one update event on every loop iteration that can be handled with every EventHandler.