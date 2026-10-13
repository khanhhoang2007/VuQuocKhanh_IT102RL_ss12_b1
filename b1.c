#include <stdio.h>
#include <string.h>

#define MAX_NV 50

typedef struct {
    int maNV;
    char hoTen[50];
    int soPhutDiMuon;
    float luongCoBan;
} NhanVien;

// Khai bao nguyen mau ham
int timTheoMaNV(NhanVien ds[], int soLuong, int maNV);
int themNhanVien(NhanVien ds[], int soLuong);
void hienThiDanhSach(NhanVien ds[], int soLuong);
void capNhatPhutDiMuon(NhanVien ds[], int soLuong);
void timKiemNhanVien(NhanVien ds[], int soLuong);
void xoaXuongDong(char chuoi[]);
int nhapSoNguyen(char thongBao[]);
float nhapSoThuc(char thongBao[]);

int main(void) {
    NhanVien ds[MAX_NV];
    int soLuong = 0;
    int luaChon;

    do {
        printf("\n===== HE THONG QUAN LY CHAM CONG HRM =====\n");
        printf("1. Them nhan vien moi\n");
        printf("2. Hien thi danh sach va tinh luong\n");
        printf("3. Cap nhat so phut di muon\n");
        printf("4. Tim kiem nhan vien theo ma\n");
        printf("0. Thoat\n");
        printf("==========================================\n");

        luaChon = nhapSoNguyen("Nhap lua chon: ");

        switch (luaChon) {
            case 1:
                soLuong = themNhanVien(ds, soLuong);
                break;
            case 2:
                hienThiDanhSach(ds, soLuong);
                break;
            case 3:
                capNhatPhutDiMuon(ds, soLuong);
                break;
            case 4:
                timKiemNhanVien(ds, soLuong);
                break;
            case 0:
                printf("Da thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (luaChon != 0);

    return 0;
}

// Xoa ky tu xuong dong trong chuoi
void xoaXuongDong(char chuoi[]) {
    chuoi[strcspn(chuoi, "\n")] = '\0';
}

// Nhap so nguyen va kiem tra du lieu
int nhapSoNguyen(char thongBao[]) {
    char dong[100];
    int giaTri;
    char kyTuThua;

    while (1) {
        printf("%s", thongBao);

        if (fgets(dong, sizeof(dong), stdin) == NULL) {
            return 0;
        }

        if (strchr(dong, '\n') == NULL) {
            int kyTu;
            while ((kyTu = getchar()) != '\n' && kyTu != EOF) {
            }
        }

        if (sscanf(dong, " %d %c", &giaTri, &kyTuThua) == 1) {
            return giaTri;
        }

        printf("Du lieu khong hop le! Vui long nhap so nguyen.\n");
    }
}

// Nhap so thuc va kiem tra du lieu
float nhapSoThuc(char thongBao[]) {
    char dong[100];
    float giaTri;
    char kyTuThua;

    while (1) {
        printf("%s", thongBao);

        if (fgets(dong, sizeof(dong), stdin) == NULL) {
            return 0;
        }

        if (strchr(dong, '\n') == NULL) {
            int kyTu;
            while ((kyTu = getchar()) != '\n' && kyTu != EOF) {
            }
        }

        if (sscanf(dong, " %f %c", &giaTri, &kyTuThua) == 1) {
            return giaTri;
        }

        printf("Du lieu khong hop le! Vui long nhap so.\n");
    }
}

// Tim vi tri nhan vien theo ma
int timTheoMaNV(NhanVien ds[], int soLuong, int maNV) {
    int i;

    for (i = 0; i < soLuong; i++) {
        if (ds[i].maNV == maNV) {
            return i;
        }
    }

    return -1;
}

// Them nhan vien moi
int themNhanVien(NhanVien ds[], int soLuong) {
    NhanVien nv;

    if (soLuong >= MAX_NV) {
        printf("Danh sach da day, khong the them!\n");
        return soLuong;
    }

    nv.maNV = nhapSoNguyen("Nhap ma nhan vien: ");

    if (nv.maNV <= 0) {
        printf("Ma nhan vien phai lon hon 0!\n");
        return soLuong;
    }

    if (timTheoMaNV(ds, soLuong, nv.maNV) != -1) {
        printf("Ma nhan vien da ton tai!\n");
        return soLuong;
    }

    printf("Nhap ho ten: ");
    if (fgets(nv.hoTen, sizeof(nv.hoTen), stdin) == NULL) {
        return soLuong;
    }
    xoaXuongDong(nv.hoTen);

    if (nv.hoTen[0] == '\0') {
        printf("Ho ten khong duoc de trong!\n");
        return soLuong;
    }

    nv.soPhutDiMuon = nhapSoNguyen("Nhap so phut di muon: ");
    if (nv.soPhutDiMuon < 0) {
        printf("So phut di muon khong duoc am!\n");
        return soLuong;
    }

    nv.luongCoBan = nhapSoThuc("Nhap luong co ban: ");
    if (nv.luongCoBan < 0) {
        printf("Luong co ban khong duoc am!\n");
        return soLuong;
    }

    ds[soLuong] = nv;
    soLuong++;

    printf("Them nhan vien thanh cong!\n");
    return soLuong;
}

// Hien thi danh sach va tinh luong
void hienThiDanhSach(NhanVien ds[], int soLuong) {
    int i;
    int tienPhat;
    float luongThucNhan;

    if (soLuong == 0) {
        printf("Danh sach nhan vien dang rong!\n");
        return;
    }

    printf("\n--- DANH SACH NHAN VIEN ---\n");
    printf("%-8s | %-25s | %-10s | %-15s\n",
           "Ma NV", "Ho ten", "Phut muon", "Luong thuc nhan");

    for (i = 0; i < soLuong; i++) {
        tienPhat = ds[i].soPhutDiMuon > 15 ? 50000 : 0;
        luongThucNhan = ds[i].luongCoBan - tienPhat;

        printf("%-8d | %-25s | %-10d | %.0f VND\n",
               ds[i].maNV,
               ds[i].hoTen,
               ds[i].soPhutDiMuon,
               luongThucNhan);
    }
}

// Cap nhat so phut di muon
void capNhatPhutDiMuon(NhanVien ds[], int soLuong) {
    int maNV;
    int viTri;
    int soPhutMoi;

    if (soLuong == 0) {
        printf("Danh sach nhan vien dang rong!\n");
        return;
    }

    maNV = nhapSoNguyen("Nhap ma NV can cap nhat: ");
    viTri = timTheoMaNV(ds, soLuong, maNV);

    if (viTri == -1) {
        printf("Khong tim thay nhan vien!\n");
        return;
    }

    soPhutMoi = nhapSoNguyen("Nhap so phut di muon moi: ");

    if (soPhutMoi < 0) {
        printf("So phut di muon khong duoc am!\n");
        return;
    }

    ds[viTri].soPhutDiMuon = soPhutMoi;
    printf("Cap nhat thanh cong!\n");
}

// Tim kiem va hien thi thong tin nhan vien
void timKiemNhanVien(NhanVien ds[], int soLuong) {
    int maNV;
    int viTri;
    int tienPhat;
    float luongThucNhan;

    if (soLuong == 0) {
        printf("Danh sach nhan vien dang rong!\n");
        return;
    }

    maNV = nhapSoNguyen("Nhap ma NV can tim: ");
    viTri = timTheoMaNV(ds, soLuong, maNV);

    if (viTri == -1) {
        printf("Khong tim thay nhan vien!\n");
        return;
    }

    tienPhat = ds[viTri].soPhutDiMuon > 15 ? 50000 : 0;
    luongThucNhan = ds[viTri].luongCoBan - tienPhat;

    printf("\n--- THONG TIN NHAN VIEN ---\n");
    printf("Ma NV: %d\n", ds[viTri].maNV);
    printf("Ho ten: %s\n", ds[viTri].hoTen);
    printf("So phut di muon: %d\n", ds[viTri].soPhutDiMuon);
    printf("Luong co ban: %.0f VND\n", ds[viTri].luongCoBan);
    printf("Tien phat: %d VND\n", tienPhat);
    printf("Luong thuc nhan: %.0f VND\n", luongThucNhan);
}