char one[][12] = {
"  $$\\   ",
"$$$$ |   ",
"\\_$$ |  ",
"  $$ |   ",
"  $$ |   ",
"  $$ |   ",
"$$$$$$\\ ",
"\\______|"};

char two[][12] = {
" $$$$$$\\  ",
"$$  __$$\\ ",
"\\__/  $$ |",
" $$$$$$  | ",
"$$  ____/  ",
"$$ |       ",
"$$$$$$$$\\ ",
"\\________|"};

const int art_length = 12;        // The length of the ascii art
const int art_height = sizeof(one)/art_length;  // The height of the ascii art

const int display_length = art_length*5;        // The length of final combined ascii art
