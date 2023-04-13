#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#define sl 100
void menu()
{
    printf("\n+--------------------------Menu------------------------+");
    printf("\n1. Them vao 1 nhan vien ");
    printf("\n2. Tim nhan vien theo ma so");
    printf("\n3. Tim nhan vien theo ten");
    printf("\n4. Bang luong cua nhan vien giam dan");
    printf("\n5. Xoa 1 nhan vien");
    printf("\n6. Thoat");
    printf("\n +--------------------------------------------------------+");
}

struct NhanVien
{
    int msvn;
    char ho[20];
    char ten[20];
    int ngay;
    int thang;
    int nam;
    char noiSinh[100];
    char diaChi[200];
    float luong;
};
typedef struct NhanVien nhanvien;

struct DanhSach
{
    nhanvien a[sl];
    int n;
};
typedef struct DanhSach danhsach;
void nhapMang(struct NhanVien *nv, int sonv)
{
    for (int i = 0; i < sonv; i++)
    {
        printf("Nhap ma so nhan vien %d: ", i + 1);
        scanf("%d", &nv[i].msvn);
        printf("Nhap ho nhan vien: ");
        scanf("%s", &nv[i].ho);
        printf("Nhap ten nhan vien: ");
        scanf("%s", &nv[i].ten);
        printf("Nhap ngay thang nam sinh nhan vien: ");
        scanf("%d%d%d", &nv[i].ngay, &nv[i].thang, &nv[i].nam);
        printf("Nhap noi sinh nhan vien: ");
        fflush(stdin);
        gets(nv[i].noiSinh);
        printf("Nhap dia chi nhan vien: ");
        fflush(stdin);
        gets(nv[i].diaChi);
        printf("Nhap luong nhan vien: ");
        scanf("%f", &nv[i].luong);
    }
}
void xuatMang(struct NhanVien *nv, int sonv)
{
    printf("\n Danh sach nhan vien: \n");
    for (int i = 0; i < sonv; i++)
    {
        printf("MSNV : %d \n Ho : %s \n Ten: %s \n Ngay thang nam sinh : %d-%d-%d \n Noi sinh:  %s \n Dia chi: %s \n Luong: %f \n",
               nv[i].msvn, nv[i].ho, nv[i].ten, nv[i].ngay, nv[i].thang, nv[i].nam, nv[i].noiSinh, nv[i].diaChi, nv[i].luong);
    }
}
void timKiemTen(struct NhanVien *nv, int n)
{
    // nhap vao gia tri can tim
    char tenTim[20];
    fflush(stdin);
    printf("Nhap ten can tim: ");
    gets(tenTim);
    for (int i = 0; i < n; i++)
    {
        if (strcmp(nv[i].ten, tenTim) == 0)
        {
            printf("MSNV : %d \n Ho : %s \n Ten: %s \n Ngay thang nam sinh : %d-%d-%d \n Noi sinh:  %s \n Dia chi: %s \n Luong: %f \n",
                   nv[i].msvn, nv[i].ho, nv[i].ten, nv[i].ngay, nv[i].thang, nv[i].nam, nv[i].noiSinh, nv[i].diaChi, nv[i].luong);
        }
    }
}
void timTheoMaSo(struct NhanVien *nv, int n)
{
    int msnvTim;
    printf("Nhap ma so nhan  vien can tim: ");
    scanf("%d", &msnvTim);
    for (int i = 0; i < n; i++)
    {
        if (msnvTim == nv[i].msvn)
        {
            printf("MSNV : %d \n Ho : %s \n Ten: %s \n Ngay thang nam sinh : %d-%d-%d \n Noi sinh:  %s \n Dia chi: %s \n Luong: %f \n",
                   nv[i].msvn, nv[i].ho, nv[i].ten, nv[i].ngay, nv[i].thang, nv[i].nam, nv[i].noiSinh, nv[i].diaChi, nv[i].luong);
        }
    }
}
void sapXep(struct NhanVien *nv, int sonv)
{
    for (int i = 0; i < sonv - 1; i++)
    {
        for (int j = i + 1; j < sonv; j++)
        {
            if (nv[i].luong < nv[j].luong)
            {
                // Hoan doi vi tri
                nhanvien nvt = nv[i];
                nv[i] = nv[j];
                nv[j] = nvt;
            }
        }
    }
}
void nhap1NV(nhanvien *nvt)
{
    // fflush(stdin);
    printf("Nhap ma so nhan vien moi: ");
    scanf("%d", &nvt->set);

    fflush(stdin);
    printf("Nhap ho nhan vien: ");
    scanf("%s", &nvt->ho);
    printf("Nhap ten nhan vien: ");
    scanf("%s", &nvt->ten);
    printf("Nhap ngay thang nam sinh nhan vien: ");
    scanf("%d%d%d", &nvt->ngay, &nvt->thang, &nvt->nam);
    printf("Nhap noi sinh nhan vien: ");
    fflush(stdin);
    gets(nvt->noiSinh);
    printf("Nhap dia chi nhan vien: ");
    fflush(stdin);
    gets(nvt->diaChi);
    printf("Nhap luong nhan vien: ");
    scanf("%f", &nvt->luong);
}
void themNV(nhanvien *nv, int sovn, int viTriThem, nhanvien *nvt)
{
    sovn++;
    nv = (struct NhanVien *)realloc(nv, sovn * sizeof(nhanvien));
    for (int i = sovn - 1; i > viTriThem; i--)
    {
        nv[i] = nv[i - 1];
    }
    nhap1NV(nvt);
    nv[viTriThem] = *nvt;
}
void xoaNV(nhanvien *nv, int *sonv, int viTriXoa)
{
    for (int i = viTriXoa; i < *sonv; i++)
    {
        nv[i] = nv[i + 1];
    }
    *sonv -= 1;
    nv = (struct NhanVien *)realloc(nv, *sonv * sizeof(nhanvien));
}
int main()
{
    int chon;
    int sonv;
    int viTriThem;
    struct NhanVien *nvt;
    printf("\n Nhap so luong nhan vien:");
    scanf("%d", &sonv);
    struct NhanVien nv[sonv];

    nhapMang(nv, sonv);
    xuatMang(nv, sonv);

    do
    {
        menu();
        printf("\nMoi ban chon menu: ");
        scanf("%d", &chon);
        switch (chon)
        {
        case 1:
        {
            (nhanvien *)malloc(sonv * sizeof(nhanvien));
            printf("Vi tri them: ");
            scanf("%d", &viTriThem);
            themNV(nv, sonv, viTriThem, nvt);
            break;
        }
        case 2:
        {
            timTheoMaSo(nv, sonv);
            break;
        }
        case 3:
        {
            timKiemTen(nv, sonv);
            break;
        }
        case 4:
        {
            sapXep(nv, sonv);
            printf("Danh sach sau khi sap xep: \n");
            xuatMang(nv, sonv);
            break;
        }
        case 5:
        {
            (nhanvien *)malloc(sonv * sizeof(nhanvien));
            int viTriXoa;
            printf("Vi tri xoa: ");
            scanf("%d", &viTriXoa);
            xoaNV(nv, &sonv, viTriXoa);
            xuatMang(nv, sonv);
            break;
        }
        case 6:
        {

            break;
        }
        default:
            printf("Moi ban chon lai");
        }
    } while (chon != 6);
}
