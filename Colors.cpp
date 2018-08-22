enum Color {
	WHITE, GREEN, RED, BLUE, ORANGE, YELLOW

}

// enum Enum{ Banana, Orange, Apple } ;
static const char * EnumStrings[] = { "white", "green","red","blue","orange", "yellow"};

const char * getTextForEnum( int enumVal )
{
  return EnumStrings[enumVal];
}