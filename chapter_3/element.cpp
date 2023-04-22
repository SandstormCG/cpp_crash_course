struct Element {

    Element* next{};
    Element* back{};

    void insert_after(Element* new_element){
        new_element->next = this->next;
        this-> next = new_element;
        new_element->back = this;

    }

    void insert_before(Element* new_element){
        new_element->next = this;
        new_element->back = this->back;
        this->back=new_element;
    }

    char prefix[2];
    short operating_number;
};


void element() {
  Element trooper1, trooper2, trooper3;
  trooper1.prefix[0] = 'T';
  trooper1.prefix[1] = 'K';
  trooper1.operating_number = 421;
  trooper1.insert_after(&trooper2);
  trooper2.prefix[0] = 'F';
  trooper2.prefix[1] = 'N';
  trooper2.operating_number = 2187;
  trooper2.insert_after(&trooper3);
  trooper3.prefix[0] = 'L';
  trooper3.prefix[1] = 'S';
  trooper3.operating_number = 005;

  for(Element* cursor = &trooper1; cursor; cursor = cursor->next) {
    cout << "Storm Trooper " << cursor->prefix[0] << cursor->prefix[1] << "-" << cursor->operating_number << std::endl;
  }

  for(Element* cursor = &trooper3; cursor; cursor = cursor->back) {
    cout << "Storm Trooper " << cursor->prefix[0] << cursor->prefix[1] << "-" << cursor->operating_number << std::endl;
  }


  // NOW BACKWARDS
  Element trooper1_b, trooper2_b, trooper3_b;
  trooper3_b.prefix[0] = 'L';
  trooper3_b.prefix[1] = 'S';
  trooper3_b.operating_number = 005;
  trooper3_b.insert_before(&trooper2_b);
  trooper2_b.prefix[0] = 'F';
  trooper2_b.prefix[1] = 'N';
  trooper2_b.operating_number = 2187;
  trooper2_b.insert_before(&trooper1_b);
  trooper1_b.prefix[0] = 'T';
  trooper1_b.prefix[1] = 'K';
  trooper1_b.operating_number = 421;

  cout << "NOW BACKWARDS" << endl;

  for(Element* cursor = &trooper1_b; cursor; cursor = cursor->next) {
    cout << "Storm Trooper " << cursor->prefix[0] << cursor->prefix[1] << "-" << cursor->operating_number << std::endl;
  }

  for(Element* cursor = &trooper3_b; cursor; cursor = cursor->back) {
    cout << "Storm Trooper " << cursor->prefix[0] << cursor->prefix[1] << "-" << cursor->operating_number << std::endl;
  }


}
