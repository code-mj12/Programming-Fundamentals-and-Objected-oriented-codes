#include "Department.cpp"
#include "Professor.cpp"
#include "University.cpp"
#include <gtest/gtest.h>
#include<iostream>
#include<string>
using namespace std;


//TASK 2

TEST(University, add) { 
University U("fast",5);
Department d("cs",5,1);
bool act=U.addDepartment(d);
ASSERT_EQ(true,act);
}

TEST(University, del) { 

University U("fast",5);
Department d("cs",5,1);
U.addDepartment(d);
bool act=U.deleteDepartment("cs");
ASSERT_EQ(1,act);
}


TEST(University, update) { 

University U("fast",5);
Department d("cs",5,1);
U.addDepartment(d);
bool act=U.updateDepartment(1,"ComputerScience");
ASSERT_EQ(true,act);
}



TEST(Department, add) { 

Department d("cs",1,5);
Professor p("Ali", 9532, "Assistant Professor");
bool act=d.addProfessor(p);
ASSERT_EQ(true,act);
}


TEST(Department,del) { 

Department d("cs",1,5);
Professor p("Ali", 9532, "Assistant Professor");
d.addProfessor(p);
bool act=d.deleteProfessor(9532);
ASSERT_EQ(true,act);
}


TEST(Department, update) { 
Department d("cs",1,5);
Professor p("Ali", 9532, "Assistant Professor");
d.addProfessor(p);
bool act=d.updateProfessor(9532,"Associate Professor");
ASSERT_EQ(true,act);
}



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}






