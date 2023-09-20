#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
namespace sdds {

	struct PostalPopulation {
		char* code;
		int pop;
	};

	bool load(const char* filename);
	bool load(PostalPopulation& record);
	void display();
	void display(const PostalPopulation& record);
	void deallocateMemory();

}
#endif // SDDS_POPULATION_H_