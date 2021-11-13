// bmp�ļ���ʽ����
typedef unsigned char BYTE;
typedef unsigned short int UINT;
typedef short int WORD;
typedef int DWORD;
typedef long LONG;
 
typedef struct tagBITMAPFILEHEADER
{
    UINT bfType;        /*˵���ļ�������*/
    DWORD bfSize;       /*˵���ļ��Ĵ�С*/
    UINT bfReserved1;   /*����������Ϊ0 */
    UINT bfReserved2;   /*����������Ϊ0*/
    DWORD bfOffBits;    /*��ͼ�����ݵ�ƫ����*/
} BITMAPFILEHEADER;
 
typedef struct tagBITMAPINFOHEADER
{
    DWORD biSize;       /*BITMAPINFOHEADER�ṹ����Ҫ���ֽ���*/
    LONG biWidth;       /*ͼ��Ŀ�ȣ�������Ϊ��λ*/
    LONG biHeight;      /*ͼ��ĸ߶ȣ�������Ϊ��λ*/
    WORD biPlanes;      /*ΪĿ���豸˵��λ��������ֵ����Ϊ1*/
    WORD biBitCount;        /*λ��/����*/
    DWORD biCompression;    /*ͼ������ѹ�������ͣ���ѹ������4/8λRLE */
    DWORD biSizeImage;      /*ͼ��Ĵ�С�����ֽ�Ϊ��λ��*/
    LONG biXPelsPerMeter;   /*ˮƽ�ֱ��ʣ�������/�ױ�ʾ*/
    LONG biYPelsPerMeter;   /*��ֱ�ֱ��ʣ�������/�ױ�ʾ*/
    DWORD biClrUsed;        /*λͼʹ�õĲ�ɫ���е���ɫ��������2/16/256/224*/
    DWORD biClrImportant;   /*��ͼ����ʾ����ҪӰ�����ɫ��������Ŀ�������0����ʾ����Ҫ*/
} BITMAPINFOHEADER;
 
 
typedef struct tagRGBQUAD   /* rgbq */
{
    BYTE rgbBlue;   /*ָ����ɫǿ��*/
    BYTE rgbGreen;  /*ָ����ɫǿ��*/
    BYTE rgbRed;    /*ָ����ɫǿ��*/
    BYTE rgbReserved; /*����������Ϊ0 */
} RGBQUAD;
 
typedef struct tagBITMAPINFO
{
    BITMAPINFOHEADER bmiHeader;     // λͼ��Ϣͷ
    RGBQUAD bmiColors[16];          // ��ɫ��
} BITMAPINFO;
 
//������Ϣ
typedef unsigned char IMAGEDATA;


//main.cpp

#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;
 
//��������
BITMAPFILEHEADER bmpHeader;         //�ļ�ͷ
BITMAPINFOHEADER bmpInfoHeader;     //�ļ���Ϣͷ
RGBQUAD *colorTable;                //��ɫ��
IMAGEDATA *bmpData;
 
int main() 
{
    char bmpFileName[80]="bmp16bit.bmp";//bmp�ļ���
    ifstream bmpFile(bmpFileName, ios::in|ios::binary);
    if(!bmpFile)
    {
        cerr<<"open error!"<<endl;
        exit(1);//�˳�����
    }
    /* ����λͼͷ */
    //���ڡ��ڴ��������(�ⲿ��Ϊ14�ֽ�)���޷�һ���Զ���������Ϣ���˴����ȡ����Ա
    bmpFile.read((char*)&bmpHeader.bfType, sizeof(bmpHeader.bfType));
    bmpFile.read((char*)&bmpHeader.bfSize, sizeof(bmpHeader.bfSize));
    bmpFile.read((char*)&bmpHeader.bfReserved1, sizeof(bmpHeader.bfReserved1));
    bmpFile.read((char*)&bmpHeader.bfReserved1, sizeof(bmpHeader.bfReserved2));
    bmpFile.read((char*)&bmpHeader.bfOffBits, sizeof(bmpHeader.bfOffBits));
    /* ��ʾλͼͷ */
    if(0x4d42!=bmpHeader.bfType)  //ǰ�����ַ�BM����ASCII��ϳ�0x4d42��Ӧ���ǹ̶���
    {
        cerr<<"not a bmp file!"<<endl;
        exit(1);
    }
    cout<<"λͼ�ļ�ͷ:"<<endl;
    cout<<"�ļ�����: BM"<<endl;
    cout<<"�ļ���С:"<<hex<<bmpHeader.bfSize<<endl;  //hex:��16�������
    cout<<"������_1:"<<bmpHeader.bfReserved1<<endl;
    cout<<"������_2:"<<bmpHeader.bfReserved2<<endl;
    cout<<"ʵ��λͼ���ݵ�ƫ���ֽ���:"<<hex<<bmpHeader.bfOffBits<<endl<<endl;
 
    /* ����λͼ��Ϣ */
    bmpFile.read((char*)&bmpInfoHeader, sizeof(bmpInfoHeader));
    /* ��ʾλͼ��Ϣ */
    cout<<"λͼ��Ϣͷ:"<<endl;
    cout<<"�ṹ��ĳ���:"<<bmpInfoHeader.biSize<<endl;
    cout<<"λͼ��:"<<bmpInfoHeader.biWidth<<endl;
    cout<<"λͼ��:"<<bmpInfoHeader.biHeight<<endl;
    cout<<"biPlanesƽ����:"<<bmpInfoHeader.biPlanes<<endl;
    cout<<"biBitCount������ɫλ��:"<<bmpInfoHeader.biBitCount<<endl;
    cout<<"ѹ����ʽ:"<<bmpInfoHeader.biCompression<<endl;
    cout<<"biSizeImageʵ��λͼ����ռ�õ��ֽ���:"<<bmpInfoHeader.biSizeImage<<endl;
    cout<<"X����ֱ���:"<<bmpInfoHeader.biXPelsPerMeter<<endl;
    cout<<"Y����ֱ���:"<<bmpInfoHeader.biYPelsPerMeter<<endl;
    cout<<"ʹ�õ���ɫ��:"<<bmpInfoHeader.biClrUsed<<endl;
    cout<<"��Ҫ��ɫ��:"<<bmpInfoHeader.biClrImportant<<endl<<endl;
 
    /*biClrUsedָ����ͼ��ʵ���õ�����ɫ���������ֵΪ�㣬���õ�����ɫ��Ϊ2^biBitCount*/
    int colorNum = bmpInfoHeader.biClrUsed;
    if(0==colorNum)
    {
        colorNum = pow(2, bmpInfoHeader.biBitCount);
    }
    colorTable = new RGBQUAD[colorNum];
 
    /* ��ȡ��ɫ����ʾ  */
    cout<<"������ɫ(R:G:B)"<<endl;
    int i;
    for(i=0; i<colorNum; i++)
    {
        bmpFile.read((char*)&colorTable[i].rgbBlue, 1);
        bmpFile.read((char*)&colorTable[i].rgbGreen, 1);
        bmpFile.read((char*)&colorTable[i].rgbRed, 1);
        bmpFile.read((char*)&colorTable[i].rgbReserved, 1);
        cout<<dec<<"["<<i<<"]="<<hex<<int(colorTable[i].rgbRed);
        cout<<":"<<int(colorTable[i].rgbGreen);
        cout<<":"<<int(colorTable[i].rgbBlue)<<endl;
    }
    cout<<endl;
 
    /*��ȡ������Ϣ*/
    bmpData = new unsigned char[bmpInfoHeader.biSizeImage];
    bmpFile.read((char*)bmpData, bmpInfoHeader.biSizeImage);
 
    /*��ʾ������Ϣ���������ʾֻ��ȡ�����ݡ�BMP�е�������Ϣ�Ǵ����ϵ����ϴ洢������ʾͼ��ʱ����ҪҪ������*/
    /*ǣ�浽ÿ���ؼ�λ-bmpInfoHeader.biBitCount-�����⣬����Ĵ��룬�е�С��*/
    int w, h;
    cout<<"������������Ϣ��"<<endl;
    for(h=0; h<bmpInfoHeader.biHeight; ++h)
    {
        cout<<"["<<setw(2)<<h<<"]: ";
        for(w=0; w < bmpInfoHeader.biSizeImage / bmpInfoHeader.biHeight; ++w)
        {
            cout<<setw(2)<<int(*(bmpData+h*bmpInfoHeader.biHeight*bmpInfoHeader.biBitCount/8+w))<<" ";
        }
        cout<<endl;
    }
    /*������ֻ������λͼ��Ϣ��Ҫ��ʾ��������Ҫ��������豸�Ĺ����ˣ��˴��Թ�*/
    delete[] bmpData;
    delete[] colorTable;
    while(1);
    return 0;
}