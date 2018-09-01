#pragma once

////static const char HTTP_TEMPLATE[] PROGMEM	= HTTP_TEMPLATE;


#define  HEADER_SGN		"{header}"
#define  BODY_SGN		"<!--body-->"
#define  FORM_SGN		"<!--form-->"
#define  ACTION_SGN		"{action}"
#define  INPUT_SGN		"<!--inp-->"


static const char  F_BODY_TEMPLATE[] PROGMEM	=	"<p><!--body-->";


//empty page
static const char  F_PAGE_TEMPLATE[] PROGMEM	=  "<!DOCTYPE html> \
<html> \
 <head> \
  <title>{header}</title> \
  <meta charset=\"utf-8\"> \
 </head> \
 <body> \
  <p><!--body--> \
  <p> \
  <!--form--> \
  <form action=\"/\"method=\"get\"> \
   <button>Home</button> \
  </form> \
 </body> \
</html>";

//submit form


static const char  F_FORMSUBMIT_TEMPLATE[] PROGMEM	= " \
<form name=\"form1\" method=\"get\" enctype=\"text/plain\" action=\"{action}\">	\
 <!--inp-->   \
 <p><input type=\"reset\" value=\"Clear\"> <input type=\"submit\" value=\"Send\"></p>	\
</form>";






