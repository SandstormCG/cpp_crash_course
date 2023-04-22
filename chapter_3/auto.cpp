
void exercise_auto() {
  auto original = 100;
  auto& original_ref = original;
  cout << "Original:  " << original << endl;
  cout << "Reference: " << original_ref << endl;

  auto new_value = 200;
  original_ref = new_value;
  cout << "Original:  " << original << endl;
  cout << "New Value: " << new_value << endl;
  cout << "Reference: " << original_ref << endl;
}
