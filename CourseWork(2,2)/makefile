test:
	cl /c search.c sort.c generate.c
	lib /OUT:array.lib search.obj sort.obj generate.obj
	cl /c test.c
	link test.obj array.lib