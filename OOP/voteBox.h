#pragma once
#include <string>
#include <vector>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
using namespace std;
class voteBox {
private:
    class User {
    public:
        int region;
        int gender;
        string name;
        int age;
        string ID;
    };
    class Citizen : public User {
        vector<int> have_vote_option;
        void Vote(int option); 	//註記投過
        void give_opinion();
    };
    class Candidate : public User {
    public:
        int index;
        string party;
        int option; //(選舉位置. 選總統)
        string politics;
        int get_voted;
        void publish_politics();
        void get_self_opinion();
    };

    class Admin : public User {
    public:
        string passwords;
        void modify_candidates();
        void modify_Citizens();
    };

    class opinion {
        string content;
        int forWho;
        int fromWho;
        string getData();
    };
    class DBconnect
    {
    public:
        sql::Driver* driver;
        sql::Connection* con;
        sql::Statement* stmt;
        DBconnect();
    };
    vector<voteBox::Candidate> candidates;
    vector<voteBox::Admin> Admins;
    vector<voteBox::Citizen>  Citizens;
    DBconnect DB;
    void Verify();
    void print_vote_result();
    void logIn();
    void show_politics(int index);
public:
    void run();    //main contral function
    voteBox();
};