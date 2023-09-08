#pragma once

template<typename T,class Deleter>
class uniqueptr {
	T* ptr = nullptr;
	Deleter deleter;
public:
	uniqueptr() = default;
	uniqueptr(T* obj) : ptr(obj) {}
	uniqueptr(const uniqueptr& obj) = delete;
	uniqueptr& operator = (const uniqueptr& obj) = delete;
	uniqueptr(uniqueptr&& obj) {
		this->ptr = obj.ptr;
		obj.ptr = nullptr;
	}
	uniqueptr& operator = (uniqueptr&& obj) {
		if (this != &obj) {
			delete ptr;
			this->ptr = obj.ptr;
			obj.ptr = nullptr;
		}
		return *this;
	}
	~uniqueptr() {
		deleter(ptr);
	}
	T operator *() {
		return *ptr;
	}
	T* operator ->(){
		return ptr;
	}
	T* get() {
		return ptr;
	}
};

template<typename T, class Deleter>
class uniqueptr<T[],Deleter> {
	T* ptr = nullptr;
	Deleter deleter;
public:
	uniqueptr() = default;
	uniqueptr(T* obj) : ptr(obj) {}
	uniqueptr(const uniqueptr& obj) = delete;
	uniqueptr& operator = (const uniqueptr& obj) = delete;
	uniqueptr(uniqueptr&& obj) {
		this->ptr = obj.ptr;
		obj.ptr = nullptr;
	}
	uniqueptr& operator = (uniqueptr&& obj) {
		if (this != &obj) {
			delete[] ptr;
			this->ptr = obj.ptr;
			obj.ptr = nullptr;
		}
		return *this;
	}
	~uniqueptr() {
		deleter(ptr);
	}
	T operator *() {
		return *ptr;
	}
	T operator [](int i) {
		return *(ptr + i);
	}
	T* operator ->() {
		return ptr;
	}
	T* get() {
		return ptr;
	}
};