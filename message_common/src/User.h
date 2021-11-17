#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User 
{
    private:
        int _id;
    public:
        User(int id, string firstName, string lastName, string email, string userName, string imageURL) : _id(id), FirstName(firstName), LastName(lastName), Email(email), UserName(userName), ImageURL(imageURL)
        {

        };
        string FirstName;
        string LastName;
        string Email;
        string UserName;
        string ImageURL;
};

#endif