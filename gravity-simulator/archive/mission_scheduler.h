/*
	File: mission_scheduler.h

	Description: mission scheduler header file; contains function declarations.

	Author: Joey Yang
*/

#ifndef MISSION_H
#define MISSION_H

#include <iostream>
#include <fstream>
#include <sstream>

class schedule {
public:
	//constructor
	schedule();

	/* rule of 3 */
	schedule(const schedule& other_schedule);
	schedule& operator=(const schedule& other_schedule);
	~schedule();

	/* class methods */
	bool schedule_empty() const;
	int get_schedule_size() const;
	void append_new_mission(const int ID, const double distance);
	void prepend_new_mission(const int ID, const double distance);
	void insert_new_mission(const int ID, const double distance, int insert_position);
	void remove_completed_mission(const int ID);
	void print_schedule() const;
	void load_missions(std::ifstream& missions_infile);
	void reverse_schedule();
	//void schedule_missions();
	

private:
	struct mission {
		int ID;
		double distance;
		mission* next;
		mission() : ID(0), distance(0), next(nullptr) {}
		mission(const int init_ID, const double init_distance) : ID(init_ID), distance(init_distance), next(nullptr) {}
	};

	mission* head;
	mission* tail;
};

#endif // MISSION_H
