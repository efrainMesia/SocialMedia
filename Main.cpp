#include "USocial.h"
#include "User.h"
#include <exception>
#include <iostream>


int main()
{
	
	USocial us2;
	User* x1 = us2.registerUser("Zi", true);
	User* x2 = us2.registerUser("gadi");
	User* x3 = us2.registerUser("yuval");



	/// empty name / onr char name not allowed 
	try
	{
		User* x44 = us2.registerUser("");
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}


	try
	{
	User* x55 = us2.registerUser("                  ");
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}


	try
	{
	User* x66 = us2.registerUser("      b           ");
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}


	try
	{
	User* x77 = us2.registerUser(" ");
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}





	/// empty post and message///////////////////////////////////////////////
	try
	{
		x1->sendMessage(x2, new Message("        "));
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}
	try
	{
		x1->sendMessage(x2, new Message(" "));
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}
	try
	{
		x1->sendMessage(x2, new Message("   A    "));
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}
	try
	{
		x1->sendMessage(x2, new Message(""));
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}



	x2->viewReceivedMessages();//only A
	
	
	// i allow empty post if there is a media .
	x2->post("        ", new Audio());
	x2->post(" ", new Audio());
	x2->post("    B ", new Audio());
	x2->post("", new Audio());
	x2->post("hi world", new Audio());
	
	try
	{
		x2->post("        ");
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}
	try
	{
		x2->post(" ");
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}
	try
	{
		x2->post("    B ");
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}
	try
	{
		x2->post("");
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}
	
	x1->addFriend(x2);
	x1->viewFriendsPosts(); //only B 


	///////////////////////end empty post and message ///////////////////////////////


	
	
	/// sending NULL as media /Message/user

	try
	{
		x2->post("FGGFGFGFFGGFGFGF", NULL);
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}

	try
	{
		x2->addFriend(NULL);
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}
	try
	{
		x2->removeFriend(NULL);
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}

	try
	{
		x1->sendMessage(x2, NULL);
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}
	try
	{
		x2->sendMessage(NULL, new Message("I ate pizza "));
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}


	//////////////////////////////////////////////////////////

	
	
	std::cout << "zzzzzzzzzzzzzzzzzzzzzzzzzzz" << std::endl;
	USocial us;
	User* z1 = us.registerUser("Zi", true);
	User* z2 = us.registerUser("Zana");

	z1->addFriend(z2);
	z2->post("y1: I hate C++!");
	std::cout << "zzzzzzzzzzzzzzzzzzzzzzzzzzz" << std::endl;
	us.removeUser(z2);
	z1->viewFriendsPosts();

	std::cout << "zzzzzzzzzzzzzzzzzzzzzzzzzzz" << std::endl;

	User* y1 = us.registerUser("Li", true);
	User* y2 = us.registerUser("Yana", true);
	User* y3 = us.registerUser("Shay");
	User* y4 = us.registerUser("hen", true);
	User* y5 = us.registerUser("Elita");
	y1->post("y1: I hate C++!");
	y2->post("y2 post: I LOVE JAVA  :)", new Audio());
	y3->post("y3: This is shit!", new Photo());
	y5->addFriend(y1);
	y5->addFriend(y2);
	y5->viewFriendsPosts(); // should see only y1, y2 s' posts
	y4->sendMessage(y5, new Message("Buy shawarma!"));
	y5->viewReceivedMessages();
	try
	{
		y3->sendMessage(y5, new Message("All your clothes  belong to me"));
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}
	y5->viewReceivedMessages();
	y3->addFriend(y5);
	y3->sendMessage(y5, new Message("I ate pizza "));
	y5->viewReceivedMessages();


	/// self error check 
	try
	{
		y2->addFriend(y2);
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}
	try
	{
		y2->removeFriend(y2);
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}
	try
	{
		y2->sendMessage(y2, new Message("I ate pizza "));
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}
	///////

	std::cout << "guy" << std::endl;


	y4->addFriend(y5);
	us.removeUser(y5);
	///  y5 rremoved you cant send email 
	try
	{
		y4->sendMessage(y5, new Message("I ate pizza "));
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}


	User* y6 = us.registerUser("shir", true);
	User* y7 = us.registerUser("dana");
	User* y8 = us.registerUser("tal");

	//buisness user can send to everyone 
	y6->sendMessage(y7, new Message("y6: I ate pizza "));
	y6->sendMessage(y8, new Message("y6: I ate pizza "));
	y6->sendMessage(y6, new Message("y6: note to self : buy some milk  "));

	y6->viewReceivedMessages();//all should have Message from y6 
	y7->viewReceivedMessages();//all should have Message from y6 
	y8->viewReceivedMessages();//all should have Message from y6 


	//y7 can not  send message to everone - regular user 
	try
	{
		y7->sendMessage(y6, new Message("y7 I ate shushi "));
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}
	try
	{
		y7->sendMessage(y8, new Message("y7 I ate shushi "));
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}
	try
	{
		y7->sendMessage(y7, new Message("y7 note to self : buy some shushi  "));
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}


	y6->viewReceivedMessages();// no message from y7 
	y7->viewReceivedMessages();// no message from y7 
	y8->viewReceivedMessages();// no message from y7 

	std::cout << "999999999999999999999999" << std::endl;








	y1->addFriend(y2);
	y1->addFriend(y3);
	y2->post("y2 post: This is awesome!", new Photo());
	y3->post("y3 post: life sucks!", new Photo());
	us.removeUser(y2);
	y1->viewFriendsPosts();//y2 removed so we cant see his posts 


	std::cout << "ora" << std::endl;

	//adding same friend twice
	y3->addFriend(y4);

	try
	{
		y3->addFriend(y4);
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}

	//remove same friend twice
	y3->removeFriend(y4);

	try
	{
		y3->removeFriend(y4);
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}


	//



	User* u1 = us.registerUser("Liron");
	User* u2 = us.registerUser("Yahav");
	User* u3 = us.registerUser("Shachaf");
	User* u4 = us.registerUser("Tsur", true);
	User* u5 = us.registerUser("Elit");
	u1->post("Hello world!");
	u2->post("I'm having a great time here :)", new Audio());
	u3->post("This is awesome!", new Photo());
	u5->post("This is awesome!", new Photo());
	u5->addFriend(u1);
	u5->addFriend(u2);
	u5->viewFriendsPosts(); // should see only u1, u2 s' posts
	u1->viewFriendsPosts(); // should see u5 posts
	u3->viewFriendsPosts(); // should see nothing
	std::cout << "**************************************************" << std::endl;
	u5->removeFriend(u1);
	try
	{
		u1->removeFriend(u5);
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}
	u5->viewFriendsPosts(); // should see only u2 s' posts
	u1->viewFriendsPosts(); // should see nothing
	u3->viewFriendsPosts(); // should see nothing

	std::cout << "**************************************************" << std::endl;



	User* u1000 = us.registerUser("dan");
	User* u1001 = us.registerUser("elior", true);
	User* u1002 = us.registerUser("moti");
	u5->addFriend(u1000);
	u5->addFriend(u1001);
	u5->addFriend(u1002);
	u5->post("This is awesome!", new Photo());
	std::cout << "@----" << std::endl;
	try {
		us.removeUser(u5);
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}
	std::cout << "@@@@@" << std::endl;
	u1000->viewFriendsPosts(); // should see nothing
	u1001->viewFriendsPosts(); // should see nothing
	u1002->viewFriendsPosts(); // should see nothing


	std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;


	try
	{
		u4->sendMessage(u5, new Message("Buy Falafel!"));
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}
	//try
	//{
	//	u5->viewReceivedMessages();
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << "error: " << e.what() << std::endl;
	//}
	u4->viewReceivedMessages();
	//try
	//{
	//	u3->sendMessage(u5, new Message("All your base are belong to us"));
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << "error: " << e.what() << std::endl;
	//}

	std::cout << "@--@" << std::endl;
	//try
	//{
	//	u5->viewReceivedMessages();
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << "error: " << e.what() << std::endl;
	//}
	//try
	//{
	//	u3->addFriend(u5);
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << "error: " << e.what() << std::endl;
	//}
	//try
	//{
	//	u3->sendMessage(u5, new Message("All your base are belong to us"));
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << "error: " << e.what() << std::endl;
	//}
	//try
	//{
	//	u5->viewReceivedMessages();
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << "error: " << e.what() << std::endl;
	//}

	try
	{
		User* u66 = us.registerUser("E");
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}

	try
	{
		User* u67 = us.registerUser(" ");
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}
	
	
	std::cout << "u1 posts****** " << std::endl;
	u1->post("u1 Hello world!");
	u1->post("u1 Hello world! 2222222222222222222", new Audio());
	u2->post(" u2 I'm having a great time here :)", new Audio());
	u3->post("u3 This is awesome!", new Photo());
	u3->post("u3 This is awesome! 333333333333333333", new Photo());
	u4->post("u4 This is awesome!", new Photo());
	u4->post("u4 This is awesome! 333333333333333333", new Photo());

	
	std::list<Post*> guy_u1 = u1->getPosts();
	std::list<Post*> guy_u3 = u3->getPosts();

	for (auto const& i : guy_u1) {
		std::cout << "u1 posts " << i->getText() << std::endl;
		if ((i->getMedia()) != NULL)
			(i->getMedia())->display();
	}

	for (auto const& i : guy_u3) {
		std::cout << "u3 posts " << i->getText() << std::endl;
		if ((i->getMedia()) != NULL) {
			(i->getMedia())->display();
			std::cout << "" << std::endl;
		}
	}

	//try
	//{
	//	u5->addFriend(u1);
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << "error: " << e.what() << std::endl;
	//}
	//
	//try
	//{
	//	u5->addFriend(u2);
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << "error: " << e.what() << std::endl;
	//}
	//
	//try
	//{
	//	u5->addFriend(u1);
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << "error: " << e.what() << std::endl;
	//}
	//
	//try
	//{
	//	u5->addFriend(u2);
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << "error: " << e.what() << std::endl;
	//}
	//
	//
	//try
	//{
	//	u5->addFriend(u1);
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << "error: " << e.what() << std::endl;
	//}
	//
	//try
	//{
	//	u5->addFriend(u3);
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << "error: " << e.what() << std::endl;
	//}
	//
	//try
	//{
	//	u5->addFriend(u5);
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << "error: " << e.what() << std::endl;
	//}




	//std::cout << "::::::::::::::::::::::::::::::" << std::endl;
	//User* u5_copy = us.getUserById(4);
	//std::cout << "::::::::::::::::::::::::::::::" << std::endl;
	//std::cout << "check getUserById" << std::endl;
	//std::cout << u5_copy->getName() << " " << u5_copy->getId() << std::endl;
	//
	//std::cout << "friends posts:" << std::endl;
	u1->viewFriendsPosts(); // should see only u1, u2 s' posts





	u4->sendMessage(u1, new Message("Buy Falafel!"));
	u1->viewReceivedMessages();

	std::cout << "*********" << std::endl;


	try
	{
		u3->sendMessage(u3, new Message("All your base are belong to us"));
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}
	u3->viewReceivedMessages();
	std::cout << "###################" << std::endl;

	try {
		u3->addFriend(u4);
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}
	std::cout << "?" << std::endl;
	u3->sendMessage(u4, new Message("All your base are belong to us"));
	std::cout << "??" << std::endl;
	u4->viewReceivedMessages();
	std::cout << "????????????????????" << std::endl;


	try
	{
		for (unsigned long i = 1; i <= 10; i++) {
			us.registerUser("Elit");
		}
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}




	User* u11 = us.registerUser("siron11");
	User* u12 = us.registerUser("sahav12");
	User* u13 = us.registerUser("ghachaf13");
	User* u14 = us.registerUser("ssur14", true);
	User* u15 = us.registerUser("slit15");

	u15->addFriend(u11);
	u15->addFriend(u12);
	u15->addFriend(u13);



	try
	{
		u15->removeFriend(u15);
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}


	try
	{
		u15->removeFriend(u13);
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}

	try
	{
		u15->removeFriend(u12);
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}

	std::cout << "remove user" << std::endl;








	std::cout << "**" << std::endl;
	//try
	//{
	//	us.removeUser(u5);
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << "error: " << e.what() << std::endl;
	//}
	//std::cout << "remove user" << std::endl;
	//
	////u5 is removed how can he post ????
	//try
	//{
	//	us.removeUser(u5);
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << "error: " << e.what() << std::endl;
	//}

	//try
	//{
	//	u5->post("u5 This is awesome! 333333333333333333", new Photo());
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << "error: " << e.what() << std::endl;
	//
	//}
	//std::cout << "remove user2222" << std::endl;
	//try
	//{
	//	u5->addFriend(u1);
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << "error: " << e.what() << std::endl;
	//}

	//try
	//{
	//	std::list<Post*> guy_u89 = u5->getPosts();
	//	for (auto const& i : guy_u89) {
	//		std::cout << "u5 posts " << i->getText() << std::endl;
	//		if ((i->getMedia()) != NULL)
	//			(i->getMedia())->display();
	//	}
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << "error: " << e.what() << std::endl;
	//}




	//try
	//{
	//	for (unsigned long i = 1; i <= 10; i++) {
	//		u3->sendMessage(u5, new Message("spam"));
	//	}
	//}

	//catch (const std::exception& e)
	//{
	//	std::cout << "error: " << e.what() << std::endl;
	//}
	//
	//try
	//{
	//	u5->viewReceivedMessages();
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << "error: " << e.what() << std::endl;
	//}


	u1->post("u1 This is awesome! 333333333333333333", new Photo());

	std::cout << "2222222222222" << std::endl;

	try
	{
		u1->addFriend(u1);
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}

	std::list<Post*> guy_u88 = u1->getPosts();


	for (auto const& i : guy_u88) {
		std::cout << "u1 posts " << i->getText() << std::endl;
		if ((i->getMedia()) != NULL)
			(i->getMedia())->display();
	}

	std::cout << "3333333333333333" << std::endl;


	//us.printUsers();

	try
	{
		u1->sendMessage(u4, new Message("spam"));
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}

	u1->addFriend(u4);


	for (unsigned long i = 1; i <= 10; i++) {
		u1->sendMessage(u4, new Message("spam"));
	}


	std::cout << "44444444444444" << std::endl;


	u4->viewReceivedMessages();

	std::cout << "end of test" << std::endl;



	return 0;
}