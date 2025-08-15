//
// Created by tonytech on 15.08.2025.
//
#pragma once
#include <string>
using namespace std;

#ifndef CPP_CAR_H
#define CPP_CAR_H

class Car {
    string brand;
    string model;
    int year;

public:
    Car(string brand, string model, const int year) : brand(std::move(brand)), model(std::move(model)), year(year) {}

    [[nodiscard]] auto GetBrand() const -> string { return this->brand; }
    [[nodiscard]] auto GetModel() const -> string { return this->model; }
    [[nodiscard]] auto GetYear() const -> int { return this->year; }
};

#endif // CPP_CAR_H
