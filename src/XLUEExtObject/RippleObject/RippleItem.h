/********************************************************************
*
* =-----------------------------------------------------------------=
* =                                                                 =
* =             Copyright (c) Xunlei, Ltd. 2004-2013              =
* =                                                                 =
* =-----------------------------------------------------------------=
* 
*   FileName    :   RippleItem
*   Author      :   ������
*   Create      :   2013-5-28
*   LastChange  :   2013-5-31
*   History     :	
*
*   Description :   ģ��һ��ˮ���䵽ˮ���Ч�����ɵ��ӣ������㷨�ο���������ӵ�ַ��
*					http://freespace.virgin.net/hugo.elias/graphics/x_water.htm
*					ˮ������ʼ�߶ȣ���ʼ�뾶��˥�����Ӿ�����ˮ������ɢ��Χ��ʹ��RippleItemGenerator
*					�������ɺ���width��ˮ�������width��С��ˮ����Ե����ַ���
*
********************************************************************/ 
#ifndef __RIPPLEITEM_H__
#define __RIPPLEITEM_H__

class RippleItem
{
public:
	RippleItem(size_t width, short radius, short height, char dampingRatio, bool fineMode);
	~RippleItem(void);

	void Draw(XL_BITMAP_HANDLE hBitmap, const RECT* lpDestRect, const RECT* lpSrcRect);

	size_t GetWidth() const
	{
		return m_width;
	}

	bool UpdateFrame();

private:

	// ��ʼ��Բ��ˮ������
	void Init();

	// ����ˮ������
	void Update(size_t& leftPoints);

	void UpdateInFineMode(const short *lpOldFrameBuffer, short* lpNewFrameBuffer, size_t& leftPoints);
	void UpdateInNormalMode(const short *lpOldFrameBuffer, short* lpNewFrameBuffer, size_t& leftPoints);

private:

	// ˮ������ɢ���䣬Ϊ����������
	size_t m_width;

	// ˮ����ʼ������뾶������ɢ����Ϊ���ģ�һ�㶼��10����������
	short m_radius;

	// ˮ����ʼ�߶ȣ���100Ϊ��׼ֵ
	short m_height;

	// ˥��ϵ����Ϊ�˱��ڼ���ʹ�ö�����˥��������1��ʾÿ��˥����Ϊ��ǰһ�룬2��ʾÿ��˥����Ϊ��ǰ1/4
	char m_dampingRatio;

	// ˮ��ģʽ����ϸģʽ����3*3����������ͨģʽֻ�������������ĵ���
	bool m_fineMode;

	// ˮ����֡���壬һ����������֡��������Ҫ����������
	// �Ժ�Ϊ�˸���ϸ���㣬����������֡����
	short *m_lpFrameBuffer1, *m_lpFrameBuffer2;

	// ��ǰ֡�Ļ�����������֡���������л�
	short *m_lpCurrentFrame;

	short m_fadeHeight;
};

// ���ˮ��������
class RippleItemGenerator
{
public:

	static RippleItem* Generate(short radius, short height, char dampingRatio, bool fineMode);
};

#endif //__RIPPLEITEM_H__