#pragma once

struct student
{
	unsigned int martric;
	char *name;
	char *address;
};

void print_student(struct student s);