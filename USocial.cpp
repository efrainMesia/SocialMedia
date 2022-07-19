#include "USocial.h"

USocial::USocial()
{
	_users = map<unsigned long, User*>();
	_id = 0;
}

User* USocial::registerUser(string username, bool add = true)
{
	User newUser = User(username);

}
