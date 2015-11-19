/***************************
Student Number : 040100411
Student Name   : Ilker Kesen
Course         : BLG252E
CRN            : 11694
Term           : 2015-Fall
Homework       : #2
***************************/

#include <iostream>
#include <fstream>

using namespace std;

class Subscriber {
    public:
        Subscriber(int, string, string, int, int);
        float compute_remaining();
        void print();
        virtual string get_subscriber_type() = 0;
    protected:
        int ID;
        string fname;
        string lname;
        int consumption_amount;
        int allowed_quota;
};

class Individual : public Subscriber {
    public:
        Individual(int, string, string, int, int, string);
        string get_subscriber_type();
    private:
        string option_code;
};

class Institutional : public Subscriber {
    public:
        Institutional(int, string, string, int, int, string);
        string get_subscriber_type();
        void print();
    private:
        string Institution_name;
};

int main(int argc, char** argv)
{
    Institutional inst(1, "Ilker", "Kesen", 5, 10, "hede");
    inst.print();
    return 0;
}

Subscriber::Subscriber(
    int ID, string fname, string lname, int consumption_amount, int allowed_quota) :
    ID(ID),
    fname(fname),
    lname(lname),
    consumption_amount(consumption_amount),
    allowed_quota(allowed_quota)
{}

float Subscriber::compute_remaining()
{
    return allowed_quota - consumption_amount;
}

Individual::Individual(int ID, string fname, string lname, int consumption_amount,
    int allowed_quota, string option_code) :
    Subscriber(ID, fname, lname, consumption_amount, allowed_quota), option_code(option_code)
{}

string Individual::get_subscriber_type()
{
    return option_code;
}

Institutional::Institutional(int ID, string fname, string lname, int consumption_amount,
    int allowed_quota, string Institution_name) :
    Subscriber(ID, fname, lname, consumption_amount, allowed_quota),
    Institution_name(Institution_name)
{}

string Institutional::get_subscriber_type()
{
    return Institution_name;
}

void Subscriber::print()
{
    cout << "Subscriber" << endl;
}

void Institutional::print()
{
    cout << "Institutional" << endl;
}
