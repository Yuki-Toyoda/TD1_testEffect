#pragma once

#ifndef Vector2D_h_
#define Vector2D_h_
#include "Vector2.h"

class Vector2D
{

public:

	float x; // x����
	float y; // y����

public:

	//�R���X�g���N�^
	
	Vector2D();
	Vector2D(float x, float y);
	Vector2D(const Vector2D& vector);
	~Vector2D();

	// �Z�b�g�֐�
	/// <summary>
	/// �[���x�N�g���ɂ���
	/// </summary>
	void setZero();
	/// <summary>
	/// ���K���x�N�g���ɂ���
	/// </summary>
	void setNormalize();
	/// <summary>
	/// �傫����ς���
	/// </summary>
	/// <param name="length">�傫��</param>
	void setMagnitude(float length);
	/// <summary>
	/// ��]������
	/// </summary>
	/// <param name="theta">��]�p�x</param>
	void setRotate(float theta);

	// const�֐� 
	/// <summary>
	/// ����
	/// </summary>
	/// <returns>float�^</returns>
	float Length() const;
	/// <summary>
	/// �����̓��
	/// </summary>
	/// <returns>float�^</returns>
	float LengthSquare() const;
	/// <summary>
	/// �x�N�g���Ƃ̋���
	/// </summary>
	/// <param name="other">�x�N�g��</param>
	/// <returns>float�^</returns>
	float DistanceFrom(const Vector2D& other) const;
	/// <summary>
	/// ����
	/// </summary>
	/// <param name="other">�x�N�g��</param>
	/// <returns>float�^</returns>
	float Dot(const Vector2D& other) const;
	/// <summary>
	/// �O��
	/// </summary>
	/// <param name="other">�x�N�g��</param>
	/// <returns>float�^</returns>
	float Cross(const Vector2D& other) const;
	/// <summary>
	/// ���K��
	/// </summary>
	/// <returns>Vector2D�^</returns>
	Vector2D Normalized() const;
	/// <summary>
	/// ��]�����x�N�g��
	/// </summary>
	/// <param name="theta">��]�p�x</param>
	/// <returns>Vector2D�^</returns>
	Vector2D Rotated(float theta) const;
	/// <summary>
	/// �傫����ς����x�N�g��
	/// </summary>
	/// <param name="length">�傫��</param>
	/// <returns>Vector2D�^</returns>
	Vector2D Magnituded(float length) const;
	/// <summary>
	/// ���˃x�N�g��
	/// </summary>
	/// <param name="normal">���K�������ǂ̖@���x�N�g��</param>
	/// <returns>Vector2D�^</returns>
	Vector2D Reflected(const Vector2D& normal) const;
	/// <summary>
	/// �ǂ���x�N�g��
	/// </summary>
	/// <param name="normal">���K�������ǂ̖@���x�N�g��</param>
	/// <returns>Vector2D�^</returns>
	Vector2D AlongWall(const Vector2D& normal) const;

	// ��r�֐�
	
	/// <summary>
	/// �[���x�N�g���ł��邩
	/// </summary>
	/// <returns>bool�^</returns>
	bool isZero() const;

	// ���Z�q�̃I�[�o�[���[�h

	Vector2D operator+() const;
	Vector2D operator-() const;
	Vector2D operator+(const Vector2D& other) const;
	Vector2D operator-(const Vector2D& other) const;
	Vector2D operator*(float s) const;
	Vector2D operator/(float s) const;
	const Vector2D& operator=(const Vector2D& other);
	const Vector2D& operator+=(const Vector2D& other);
	const Vector2D& operator-=(const Vector2D& other);
	const Vector2D& operator*=(float s);
	const Vector2D& operator/=(float s);
	bool operator==(const Vector2D& other) const;
	bool operator!=(const Vector2D& other) const;

	// �\��
	static void Printf(int y, const Vector2D& m);

};

Vector2D operator*(float s, const Vector2D& vector);

// Novice��Vector2

// ����
float Length(const Vector2& vector);
// ����
float Distance(const Vector2& vector, const Vector2& other);
// ����
float Dot(const Vector2& vector, const Vector2& other);
// �O��
float Cross(const Vector2& vector, const Vector2& other);
// ���K��
Vector2 Normalized(const Vector2& vector);
// ��]
Vector2 Rotated(const Vector2& vector, float theta);
// �傫��
Vector2 Magnituded(const Vector2& vector, float length);

// ���Z�q�̃I�[�o�[���[�h
Vector2 operator+(const Vector2& vector1, const Vector2& vector2);
Vector2 operator-(const Vector2& vector1, const Vector2& vector2);
Vector2 operator*(const Vector2& vector, float s);
Vector2 operator*(float s, const Vector2& vector);
Vector2 operator/(const Vector2& vector, float s);



#endif // Vector2D_h_