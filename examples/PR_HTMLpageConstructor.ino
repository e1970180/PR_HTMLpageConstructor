
#include "PR_HTMLpageConstructor.hpp"
#include <Esp.h>                    // core


void    setup() {
	
    Serial.begin(115200);
    Serial.flush();
	Serial.println();
	

	Serial.print("free mem=");Serial.println( ESP.getFreeHeap() );
	
	HTMLpageConstructorClass p1("tst header");
	
	Serial.print("free mem=");Serial.println( ESP.getFreeHeap() );
	
	p1.addBodyText(F("body text<br>new line") );
	p1.addSubmitForm("formhandel");
	p1.addInputPort("name1", "textPort", 123);
	p1.addInputIP("name2", "textIP");
	

	//p1.dbgPrint();
	
	Serial.print("free mem=");Serial.println( ESP.getFreeHeap() );
	
}

void    loop() {
	

}	