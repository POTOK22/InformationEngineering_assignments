#include "header.h"

int main()
{
    Invoice inv(7770003699, 01234567);
//    inv.print();
//    Item it("M3 screw", 0.37, 'A', 100);
//    it.print();
    inv.add_item(Item("M3 screw", 0.37, 'A', 100));
    inv.add_item(Item("2 mm drill", 2.54, 'B', 2));
    cout<<inv<<endl;
    return 0;
}
