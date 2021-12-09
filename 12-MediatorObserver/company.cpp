
#include "company.h"
#include "communications.h"

void Employee::sendMessage(Mediator* mp, const std::string& msg) {
	mp->distributeMessage(this, msg);
}