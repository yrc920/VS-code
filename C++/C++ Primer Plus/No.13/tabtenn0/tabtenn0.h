//tabtenn0.h -- a table tennis base class
#ifndef TABTENN0_H__
#define TABTENN0_H__
#include <string>
using std::string;

class TableTennisPlayer
{
    private:
        string firstname;
        string lastname;
        bool hasTable;
    public:
        TableTennisPlayer(const string &fn = "none", const string &ln = "none", bool ht = false);
        void Name() const;
        bool HasTable() const { return hasTable; }
        void ResetTable(bool v) { hasTable = v; }
};

#endif

