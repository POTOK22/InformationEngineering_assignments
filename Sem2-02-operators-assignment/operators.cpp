#include "header.h"

/*Invoice methods*/
Invoice::Invoice(double nip, double buyer, vector<Item> v) : nip_number_(nip), buyer_number_(buyer), set_bought_items_(v){}

void Invoice::set_nip(double nip){
    nip_number_=nip;
}
double Invoice::nip() const {
    return nip_number_;
}
void Invoice::set_buyer(double buyer){
    buyer_number_=buyer;
}
double Invoice::buyer() const {
    return buyer_number_;
}
//void Invoice::print() const {
//    cout<<fixed<<setprecision(2)<<nip_number_<<" "<<buyer_number_<<endl;
//}
void Invoice::set_v(vector<Item> v){
    set_bought_items_=v;
}
vector<Item> Invoice::v() const{
    return set_bought_items_;
}
Invoice Invoice::operator*(const Invoice &rhs) const {
    return Invoice(set_bought_items_[0].unit() * rhs.set_bought_items_[0].amount());
}
ostream &operator<<(ostream &str, Invoice &rhs){
    str<<"------------------VAT invoice------------------"<<endl;
    str<<"==============================================="<<endl;
    str<<fixed<<setprecision(0)<<"Seller: "<<rhs.nip()<<"      Buyer: "<<dec<<rhs.buyer()<<endl;
    str<<"                  c.j. VAT   il.    net   total"<<endl;
    double sum_net=0;
    double sum_tot=0;
    for (int i=0; i<rhs.set_bought_items_.size(); i++){
        double sum_A;
        double sum_B;
        double sum_C;
        if(rhs.set_bought_items_[i].vat()=='A'){
            sum_A=(rhs.set_bought_items_[i].unit() * rhs.set_bought_items_[i].amount())*1.23;
            str<<fixed<<setprecision(2)<<i+1<<". "<<rhs.set_bought_items_[i].name()<<"\t| "<<rhs.set_bought_items_[i].unit()<<"  "<<
                 rhs.set_bought_items_[i].vat()<<" | "<<rhs.set_bought_items_[i].amount()<<"\t| "<<
                 rhs.set_bought_items_[i].unit() * rhs.set_bought_items_[i].amount()<<"\t| "<<
                 sum_A<<endl;
        }
        if(rhs.set_bought_items_[i].vat()=='B'){
            sum_B=(rhs.set_bought_items_[i].unit() * rhs.set_bought_items_[i].amount())*1.08;
            str<<i+1<<". "<<rhs.set_bought_items_[i].name()<<"\t| "<<rhs.set_bought_items_[i].unit()<<"  "<<
                 rhs.set_bought_items_[i].vat()<<" | "<<rhs.set_bought_items_[i].amount()<<"\t| "<<
                 rhs.set_bought_items_[i].unit() * rhs.set_bought_items_[i].amount()<<"\t| "<<
                 sum_B<<endl;
        }
        if(rhs.set_bought_items_[i].vat()=='C'){
            sum_C=rhs.set_bought_items_[i].unit() * rhs.set_bought_items_[i].amount();
            str<<i+1<<". "<<rhs.set_bought_items_[i].name()<<"\t| "<<rhs.set_bought_items_[i].unit()<<"  "<<
                 rhs.set_bought_items_[i].vat()<<" | "<<rhs.set_bought_items_[i].amount()<<"\t| "<<
                 rhs.set_bought_items_[i].unit() * rhs.set_bought_items_[i].amount()<<"\t| "<<
                 sum_C<<endl;
        }
        sum_net+=rhs.set_bought_items_[i].unit()*rhs.set_bought_items_[i].amount();
        sum_tot=sum_A+sum_B+sum_C;
    }
    str<<endl;
    str<<"------------------------------------ TOTAL ----"<<endl;
    str<<"\t\t\t\t  "<<sum_net<<" | "<<sum_tot<<endl;
    return str;
}

/*Item methods*/
Item::Item(string name, double unit, char vat, int amount) : name_(name), unit_per_price_(unit),
    vat_tax_(vat), amount_of_sold_(amount){};

void Item::set_name(string name){
    name_=name;
}
string Item::name() const {
    return name_;
}
void Item::set_unit(double unit){
    unit_per_price_=unit;
}
double Item::unit() const {
    return unit_per_price_;
}
void Item::set_vat(char vat){
    vat_tax_=vat;
}
char Item::vat() const {
    return vat_tax_;
}
void Item::set_amount(int amount){
    amount_of_sold_=amount;
}
int Item::amount() const {
    return amount_of_sold_;
}
void Item::print() const {
    cout<<name_<<" "<<unit_per_price_<<" "<<vat_tax_<<" "<<amount_of_sold_<<endl;
}
ostream &operator<<(ostream &str, Item &rhs){
    return str;
}
