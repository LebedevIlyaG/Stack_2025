#pragma once

#include <iostream>

template <class T>
class TStack
{
protected:
  T** data;
  int len;
  bool isNew;
  int top;
public:
  TStack();
  TStack(int len_);
  TStack(const TStack& obj);
  TStack(TStack&& obj);
  TStack(T** data_, int len_);
  ~TStack();

  int GetLen();

  void Resize(int len_);
  void SetData(T** data_, int len_);

  void Push(T value);

  T Pop();

  bool IsEmpty();
  bool isFull();


  TStack& operator=(const TStack<T>& obj);
  TStack& operator=(TStack<T>&& obj);
  bool operator==(const TStack<T>& obj);
  bool operator!=(const TStack<T>& obj);


  template <class O>
  friend std::ostream& operator<<(std::ostream& o, TStack<O>& v);
  template <class I>
  friend std::istream& operator>>(std::istream& i, TStack<I>& v);


};

template<class T>
inline TStack<T>::TStack()
{
  data = nullptr;
  len = 0;
  isNew = true;
  top = 0;
}

template<class T>
inline TStack<T>::TStack(int len_) : TStack<T>::TStack()
{
  if (len < 0)
  {
    throw - 1;
  }
  else if (len > 0)
  {
    len = len_;
    data = new T * [len];
    for (int i = 0; i < len; i++)
    {
      data[i] = nullptr;
    }
  }
}

template<class T>
inline TStack<T>::TStack(const TStack& obj) : TStack<T>::TStack()
{
  if (obj.len > 0)
  {
    len = obj.len;
    data = new T * [len];
    for (int i = 0; i < len; i++)
    {
      data[i] = new T(obj.data[i]);
    }
  }
  top = obj.top;
}

template<class T>
inline TStack<T>::TStack(TStack&& obj)
{
  len = obj.len;
  data = obj.data;
  top = obj.top;
  isNew = obj.isNew;

  obj.len = 0;
  obj.data = nullptr;
  obj.isNew = true;
}

template<class T>
inline TStack<T>::TStack(T** data_, int len_) : TStack<T>::TStack()
{
  if (len < 0)
  {
    throw - 1;
  }
  else if (len > 0)
  {
    len = len_;
    data = data_;
    isNew = false;
    for (int i = 0; i < len; i++)
    {
      if (data[i] == nullptr)
      {
        top = i;
        break;
      }
    }
  }
}

template<class T>
inline TStack<T>::~TStack()
{
  if (isNew)
  {
    if (data != nullptr)
    {
      for (int i = 0; i < len; i++)
      {
        delete data[i];
      }

      delete[] data;
    }
  }

  data = nullptr;
  isNew = true;
  len = 0;
}

template<class T>
inline int TStack<T>::GetLen()
{
  return len;
}


template<class T>
inline void TStack<T>::Resize(int len_)
{
  if (len_ < 0)
  {
    throw - 1;
  }
  else if (len_ == 0)
  {

    if (isNew)
    {
      if (data != nullptr)
      {
        for (int i = 0; i < len; i++)
        {
          delete data[i];
        }

        delete[] data;
      }
    }

    data = nullptr;
    isNew = true;
    len = 0;
  }
  else if (len_ == len)
  {
    return;
  }
  else
  {
    T** newData = new T * [len_];
    int i = 0;
    for (; i < std::min(len, len_); i++)
    {
      newData[i] = data[i];
    }
    if (isNew)
    {
      for (; i < len; i++)
      {
        delete data[i];
      }
      delete[] data;
    }
    data = newData;
    len = len_;
    isNew = true;
  }
  
}

template<class T>
inline void TStack<T>::SetData(T** data_, int len_)
{

  if (len_ < 0)
  {
    throw - 1;
  }
  else if (len_ == 0)
  {

    if (isNew)
    {
      if (data != nullptr)
      {
        for (int i = 0; i < len; i++)
        {
          delete data[i];
        }

        delete[] data;
      }
    }

    data = nullptr;
    isNew = true;
    len = 0;
  }
  else if (len_ > 0)
  {
    if (isNew)
    {
      if (data != nullptr)
      {
        for (int i = 0; i < len; i++)
        {
          delete data[i];
        }

        delete[] data;
      }
    }

    data = nullptr;
    data = data_;
    len = len_;
    for (int i = 0; i < len; i++)
    {
      if (data[i] == nullptr)
      {
        top = i;
        break;
      }
    }
  }

}

template<class T>
bool TStack<T>::IsEmpty()
{
  if (top == 0)
    return true;
  else
    return false;
}

template<class T>
bool TStack<T>::isFull()
{
  if (top >= len)
    return true;
  return false;
}

template<class T>
inline void TStack<T>::Push(T value)
{
  if (isFull())
    throw - 1;
  
  data[top] = new T(value);
  top++;
}

template<class T>
inline T TStack<T>::Pop()
{
  if (IsEmpty())
    throw - 1;
  top--;
  return data[top + 1];
}

template<class T>
inline TStack<T>& TStack<T>::operator=(const TStack<T>& obj)
{
  return *this;
  // TODO: вставьте здесь оператор return
}

template<class T>
inline TStack<T>& TStack<T>::operator=(TStack<T>&& obj)
{
  return *this;
  // TODO: вставьте здесь оператор return
}

template<class T>
inline bool TStack<T>::operator==(const TStack<T>& obj)
{
  return false;
}

template<class T>
inline bool TStack<T>::operator!=(const TStack<T>& obj)
{
  return false;
}

template<class O>
inline std::ostream& operator<<(std::ostream& o, TStack<O>& v)
{
  return o;
  // TODO: вставьте здесь оператор return
}

template<class I>
inline std::istream& operator>>(std::istream& i, TStack<I>& v)
{
  return i;
  // TODO: вставьте здесь оператор return
}
