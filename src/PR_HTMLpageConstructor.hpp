#pragma once

#include "PR_HTMLpageTemplates.h"

typedef struct InputAttib {
	String	txt;
	String	id;
	String	name;
	String	type;
	String	value;
	String	pattern;
	String	placeholder;
	String	min;
	String	max;
	String	maxlength;	
} InputAttib_t;

class HTMLpageConstructorClass {
	
	public:
	
		HTMLpageConstructorClass();
		HTMLpageConstructorClass(const char* header);
		HTMLpageConstructorClass(const String& header);
		
	
		bool	init();
	
		bool	addBodyText(const String& body);
		bool	addSubmitForm(const String& submitHandler);
		void	addInput(const InputAttib_t& attr);
		
		void	addInputPort(const String& name, const String& text, const uint16_t portDefVal = 0);
		void	addInputIP(const String& name, const String& text);
		void	addInputURL(const String name);
		
		void	dbgPrint();

		String			html;
		InputAttib_t	inputAttr;
		
	protected:
		bool	_isFormAdded;	
		
		const String	_headerSgn	= HEADER_SGN;
		const String	_formSgn	= FORM_SGN;
		const String	_actionSgn	= ACTION_SGN;
		const String	_inputSgn	= INPUT_SGN;
		const String	_bodySgn	= BODY_SGN;
	
};

HTMLpageConstructorClass::HTMLpageConstructorClass() {
	init();
} 

HTMLpageConstructorClass::HTMLpageConstructorClass(const char* header) {
	init();
	html.replace(_headerSgn, header);
}

HTMLpageConstructorClass::HTMLpageConstructorClass(const String& header) {
	init();
	html.replace(_headerSgn, header);
}

//load template from EEPROM or file system or ever
bool	HTMLpageConstructorClass::init() {
	html = FPSTR(F_PAGE_TEMPLATE);
	_isFormAdded = false;
	return true;
}  


bool	HTMLpageConstructorClass::addBodyText(const String& body) {

	html.replace(_bodySgn, body + FPSTR(F_BODY_TEMPLATE) ); //insert into first section and adding one more section
	return true;
}	
	
bool	HTMLpageConstructorClass::addSubmitForm(const String& submitHandler) {
	
	if ( _isFormAdded ) return false; //form could be added once only
	if ( submitHandler == "" ) return false;
	
	String	code;
	code.reserve(200); //estimated length of generated code

	code = FPSTR(F_FORMSUBMIT_TEMPLATE);
	code.replace(_actionSgn, submitHandler); 
	
	html.replace(_formSgn, code);
	_isFormAdded = true;
	
	return true;
}
	
	
void	HTMLpageConstructorClass::addInput(const InputAttib_t& attr) {
	
	String	code;
	code.reserve(300); //estimated length of generated code
	
	code = "<p>";
	code += attr.txt;
	code += F("<input id=\"");
	code += attr.id;
	code += F("\"name=\"");
	code += attr.name;
	code += F("\"type=\"");
	code += attr.type;
	code += F("\"value=\"");
	code += attr.value;
	code += F("\"pattern=\"");
	code += attr.pattern;
	code += F("\"placeholder=\"");
	code += attr.placeholder;
	code += F("\"min=\"");
	code += attr.min;
	code += F("\"max=\"");
	code += attr.max;
	code += F("\"maxlength=\"");
	code += attr.maxlength;
	code += F("\"maxlength=\"");
	code += attr.maxlength;
	code += F("\"></p>");
	code += _inputSgn;

	html.replace(_inputSgn, code);
}


void	HTMLpageConstructorClass::addInputPort(const String& name, const String& text, const uint16_t portDefVal) {
	
	inputAttr.txt = text;
	inputAttr.id = "" ;
	inputAttr.name = name;
	inputAttr.type = "number";
	if ( portDefVal ) inputAttr.value = String(portDefVal);
	else inputAttr.value = "";
	inputAttr.pattern = "" ;
	inputAttr.placeholder = "port number" ;
	inputAttr.min = "1";	
	inputAttr.max = "65365";
	inputAttr.maxlength = "";
	
	addInput(inputAttr);
	
}


void	HTMLpageConstructorClass::addInputIP(const String& name, const String& text) {
	
	inputAttr.txt = text;
	inputAttr.id = "" ;
	inputAttr.name = name;
	inputAttr.type = "number";
	inputAttr.pattern = "\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}" ;
	inputAttr.placeholder = "IP address" ;
	inputAttr.value = "" ;
	inputAttr.min = "";	
	inputAttr.max = "";
	inputAttr.maxlength = "";
	
	addInput(inputAttr);
}

void	HTMLpageConstructorClass::addInputURL(const String name) {
	inputAttr.id = "" ;
	inputAttr.name = name;
	//inputAttr.type = "number";
	//inputAttr.pattern = "\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}" ;
	inputAttr.placeholder = "URL" ;
	inputAttr.value = "" ;
	inputAttr.min = "";	
	inputAttr.max = "";
	inputAttr.maxlength = "";
	
	addInput(inputAttr);
}




void	HTMLpageConstructorClass::dbgPrint() {
	
	Serial.println(html);
}