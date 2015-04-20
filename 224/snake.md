# Snake Help Session

1. Interupt Driven Programming
	- Main Function
	- Sys_events
	- WDT_ISR
2. Snake array/new it, moves
3. Structs, typedef, union, function pointers

lots of draw functions LCD_

LCD_crusor(x,y)
   _printf("String")
Turn on printf support to minimum

LCD_update_event() 
	every 1 second intervals
	update the time and the score
	writes over the score and time ("%d", integer)

WDT_SR 
	checks for debouncing
	if (sys events) wake up proessor on exit

define swtich 1 event 0x01 
	....				x08
						010

while(1) {
	sleep processor
		if (sys_events)
			if (sysevents & movesnake(or similar))
				sys_events &= ~movesnake
				movesnake function
			else if (sysevents & lcdupdate)
			... 
			...
			else 

snake is an array of positions
head and tail variable are indexes into the array

head = (head + 1) & ~MAX_SNAKE

typdef struct {
	point position
	size
	value
	(void*) draw(x,y)

newFood() {
	draw = & drawfoodfunc;
}
}food

food* [10]