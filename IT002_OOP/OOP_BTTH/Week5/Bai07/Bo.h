#pragma once
#include "GiaSuc.h"
#include <cstdlib>

class Bo : public GiaSuc {
public:
    void Keu() override;
    int SinhCon() override;
    int ChoSua() override;
    int GetLoai() override;
};