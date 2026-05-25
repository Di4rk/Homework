#pragma once
#include "KhachBTH.h"
#include "KhachThan.h"
#include "KhachVIP.h"
#include <vector>

class CongTy
{
private:
	std::vector<KhachBTH*> dsKhachBTH;
	std::vector<KhachThan*> dsKhachThan;
	std::vector<KhachVIP*> dsKhachVIP;
	int x, y, z;
public:
	void xuLyDuLieu(const std::string& fileINP, const std::string& fileOUT);
	~CongTy();
};

