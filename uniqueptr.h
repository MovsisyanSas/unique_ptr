#pragma once

template<typename T>
class uniqueptr {
	T* ptr = nullptr;
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
			this->ptr = obj.ptr;
			obj.ptr = nullptr;
		}
		return *this;
	}
	~uniqueptr() {
		ptr = nullptr;
		delete ptr;
	}
	T operator *() {
		return *ptr;
	}
	T* operator ->(){
		return ptr;
	}
	T operator [](int i){
		return *(ptr + i);
	}
};
