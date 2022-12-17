#include "voteBox.h"
#include <string>
using namespace std;
voteBox::DBconnect::DBconnect()
{
	const string server = "114.35.222.181:3306";
	const string username = "OopAdmin";
	const string password = "147422Ff";
	try
	{
		driver = get_driver_instance();
		con = driver->connect(server, username, password);
	}
	catch (sql::SQLException e)
	{
		cout << "Could not connect to server. Error message: " << e.what() << endl;
		system("pause");
		exit(1);
	}
	con->setSchema("oop");
	stmt = con->createStatement();
	return;
}
voteBox::voteBox()
{
	//create admin list
	sql::ResultSet* res;
	res = DB.stmt->executeQuery("SELECT * FROM user NATURAL JOIN admin; ");
	Admins.clear();
	while (res->next()) {
		Admin admin;
		admin.ID = res->getString("ID");
		admin.name = res->getString("name");
		admin.passwords = res->getString("password");
		Admins.push_back(admin);
	}

	res = DB.stmt->executeQuery("SELECT * FROM user NATURAL JOIN candidate;");
	candidates.clear();
	while (res->next()) {
		Candidate candidate;
		candidate.ID = res->getString("ID");
		candidate.name = res->getString("name");
		candidate.age = res->getInt("age");
		candidate.region = res->getInt("region");
		candidate.gender = res->getInt("gender");
		candidate.politics = res->getString("politics");
		candidate.get_voted = res->getInt("get_voted");
		candidate.index = res->getInt("Candidate_num");
		candidate.option = res->getInt("vote_option");
		candidates.push_back(candidate);
	}

	res = DB.stmt->executeQuery("SELECT * FROM user \
								WHERE ID NOT IN \
								(SELECT ID \
									FROM user NATURAL JOIN admin) \
								AND ID NOT IN \
								(SELECT ID \
									FROM user NATURAL JOIN candidate); ");
	Citizens.clear();
	while (res->next()) {
		Citizen citizen;
		citizen.ID = res->getString("ID");
		citizen.name = res->getString("name");
		citizen.age = res->getInt("age");
		citizen.region = res->getInt("region");
		citizen.gender = res->getInt("gender");
		Citizens.push_back(citizen);
	}
	cout << candidates.size() << " " << Citizens.size() << " " << Admins.size() << endl;
	return;
}

void voteBox::Verify()
{
}

void voteBox::print_vote_result()
{
}

void voteBox::logIn()
{
}

void voteBox::show_politics(int index)
{
}

void voteBox::run()
{
	return ;
}

void voteBox::Citizen::Vote(int option)
{
}

void voteBox::Citizen::give_opinion()
{
}

void voteBox::Candidate::publish_politics()
{
}

void voteBox::Candidate::get_self_opinion()
{
}

void voteBox::Admin::modify_candidates()
{
}

void voteBox::Admin::modify_Citizens()
{
}

string voteBox::opinion::getData()
{
	string re = "";
	return re;
}
