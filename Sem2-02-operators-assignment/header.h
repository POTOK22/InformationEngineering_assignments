#ifndef HEADER_H
#define HEADER_H
#pragma once

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class Item{
public:
    Item(string name=0, double unit=0.0, char vat=0, int amount=0);
    void set_name(string name_);
    void set_unit(double unit_per_price_);
    void set_vat(char vat_tax_);
    void set_amount(int amount_of_sold_);
    string name() const;
    double unit() const;
    char vat() const;
    int amount() const;
    void print() const;
    friend ostream &operator<<(ostream &str, Item &rhs);
private:
    string name_;
    double unit_per_price_;
    char vat_tax_;
    int amount_of_sold_;
};

class Invoice{
public:
    Invoice(double nip=0, double buyer=0, vector<Item> v={});
    void set_nip(double nip_number_);          //setter for nip
    void set_buyer(double buyer_number_);      //setter for item
    void set_v(vector<Item> set_bought_items_);
    double nip() const;      //getter for nip
    double buyer() const;     //getter for item
    vector<Item> v() const;
    void print() const;
    void add_item(Item a){
        set_bought_items_.push_back(a);
    };
    friend ostream &operator<<(ostream &str, Invoice &rhs);
    Invoice operator*(const Invoice &rhs) const;
private:
    double nip_number_;
    double buyer_number_;
    vector<Item> set_bought_items_;
};

#endif // HEADER_H
