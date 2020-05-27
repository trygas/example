#include "general.h"

#include <GSLAM/core/Messenger.h>
#include <GSLAM/core/Glog.h>

void receiveString(const shared_ptr<string>& msg)
{
    LOG(INFO) << "Receive String " << *msg << endl;
}

int main()
{
    using namespace GSLAM;
    Publisher pubStr = Messenger::instance().advertise<string>("string", 0);

    std::function<void(const std::shared_ptr<std::string>&)> receiveStr = [](const shared_ptr<string>& msg){
        cout << *msg;
    };
    Subscriber subStr = Messenger::instance().subscribe("string", 0, receiveStr);
    pubStr.publish(string("haha"));
    pubStr.publish(string("shabi"));
}
