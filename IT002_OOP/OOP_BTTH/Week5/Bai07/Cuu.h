#pragma once
#include "GiaSuc.h"
#include <cstdlib>

class Cuu : public GiaSuc {
public:
    void Keu() override;
    int SinhCon() override;
    int ChoSua() override;
    int GetLoai() override;
};