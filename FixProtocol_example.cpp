#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>

int main()
{
    std::vector<std::string> vFields;

    std::string fix_msg =
        "8=FIX.4.4\x01"
        "9=148\x01"
        "35=D\x01"
        "34=1080\x01"
        "49=TESTBUY1\x01"
        "52=20180920-18:14:19.508\x01"
        "56=TESTSELL1\x01"
        "11=636730640278898634\x01"
        "15=USD\x01"
        "21=2\x01"
        "38=7000\x01"
        "40=1\x01"
        "54=1\x01"
        "55=MSFT\x01"
        "60=20180920-18:14:19.492\x01"
        "10=092\x01";

    std::map<std::string, std::string> fieldNames =
    {
        {"8",  "BeginString"},
        {"9",  "BodyLength"},
        {"10", "CheckSum"},
        {"11", "ClOrdID"},
        {"15", "Currency"},
        {"21", "HandlInst"},
        {"34", "MsgSeqNum"},
        {"35", "MsgType"},
        {"38", "OrderQty"},
        {"40", "OrdType"},
        {"49", "SenderCompID"},
        {"52", "SendingTime"},
        {"54", "Side"},
        {"55", "Symbol"},
        {"56", "TargetCompID"},
        {"60", "TransactTime"}
    };

    std::string tmp;

    for (char i : fix_msg)
    {
        if (i == '\x01')
        {
            vFields.push_back(tmp);
            tmp.clear();
            continue;
        }
        tmp.push_back(i);
    }

    std::map<std::string, std::string> mTagValues;

    for (const auto& field : vFields)
    {
        std::string tag;
        std::string tagValue;

        size_t pos = field.find('=');

        tag = field.substr(0, pos);
        tagValue = field.substr(pos + 1);

        auto tagPair = fieldNames.find(tag);

        mTagValues.emplace(tagPair->second, tagValue);
    }

    std::fstream fs;
    std::string fname = "Fix Protocol.txt";


    fs.open(fname,std::fstream::in|std::fstream::out|std::fstream::app);

    if (!fs.is_open())
    {
        std::cout << "File not open" << std::endl;
    }
    else
    {
        for (const auto& i : mTagValues)
        {
            fs << i.first<< "\t" << " = " << i.second << '\n';
        }
    }



    return 0;
}
