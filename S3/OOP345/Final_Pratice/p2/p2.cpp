// Question 1

struct Gem
{
  string name;
  string colour;
  int shine;
  bool polished;
};

// Create a Box class has the following properties:

// An STL container of Gems as a data member
// A += operator that adds Gems to the box
// A -= operator that removes Gems from the Box based on a given string (name) to search for. If the string is found then remove any Gems that match. If there isn’t a match at all then throw an exception of string type with a relevant error message
// A function called process that doesn’t receive any parameters nor returns any value. This function will iterate through the Gems in the Box and polish them if they aren’t yet polished. Polishing a Gem will cause its shine value to increase by 20. For this functionality incorporate the use of threads to divide the work.
// A display function that displays the contents of the box
// The following main will use the Box class:

int main()
{
  Box b;

  cout << "\nAdding Gems" << endl;
  b += Gem{"Emerald", "Green", 20, false};
  b += Gem{"Ruby", "Red", 50, true};
  b += Gem{"Sapphire", "Blue", 80, false};
  b += Gem{"Onyx", "Black", 60, false};
  b += Gem{"Opal", "White", 10, false};
  b.display();

  cout << "\nRemoving Gems" << endl;
  try
  {
    b -= "Ruby";
    b -= "Emerald";
    b -= "Diamond";
    b.display();
  }
  catch (string c)
  {
    cout << c << endl;
  }

  cout << "\nPolishing Gems" << endl;
  b.process();
  b.display();

  cout << "\nVector of Boxes" << endl;
  vector<Box *> boxes;
  boxes.push_back(newBox());
  boxes.push_back(newBox());
  boxes.push_back(newBox());

  for (auto x : boxes)
  {
    x->operator+=(Gem{"Emerald", "Green", 20, false});
    x->operator+=(Gem{"Ruby", "Red", 90, false});
    x->operator+=(Gem{"Sapphire", "Blue", 40, false});
  }

  for (auto x : boxes)
  {
    delete x;
  }
}

// As an extra task, modify the Box class to instead have a container of Gem pointers and apply the use of smart pointers to the solution.