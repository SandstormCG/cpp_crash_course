using namespace std;

char read_from(char* array,int size, int position) {
    if (position<size) {
        return *(array + position);
    } else {
        return  '\0';
    }
}

void write_to(char* array,int size, int position, char value) {
    if (position<size) {
        *(array + position)=value;
    } else {
        std::cout << "OUT OF BOUNDS!!" << std::endl;
    }
}

void pointers() {
    char lower[] = "abd?e";
    char upper[] = "ABD?E";
    char* upper_ptr = upper;

    lower[3] = 'd';
    upper_ptr[3]= 'D';

    char letter_d = lower[3];
    char letter_D = upper_ptr[3];

    std::cout << "lower: " << lower << std::endl << "upper: " << upper << std::endl;
    std::cout << "letter_d: " << letter_d << std::endl << "letter_D: " << letter_D << std::endl;

    char read_letter_d = read_from(lower, sizeof(lower),3);
    char read_letter_D= read_from(upper, sizeof(upper), 3);
    char oob_letter = read_from(lower, sizeof(lower), 5);

    std::cout << "letter_d: " << letter_d << std::endl << "letter_D: " << letter_D << std::endl;
    std::cout << "Out of bounds leter: " << oob_letter << std::endl;

    char letter_s = 's';
    char letter_S = 'S';

    lower[3] = letter_s;
    upper_ptr[3] = letter_S;

    std::cout << "lower: " << lower << std::endl << "upper_ptr: " << upper_ptr << std::endl;

    write_to(lower, sizeof(lower),2, letter_s);
    write_to(upper_ptr, sizeof(upper_ptr),2, letter_S);
    write_to(lower, sizeof(lower),6, letter_S);   // write OOB

    std::cout << "lower: " << lower << std::endl << "upper_ptr: " << upper_ptr << std::endl;

}
