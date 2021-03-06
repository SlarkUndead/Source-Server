/*
 * Copyright 1999-2000,2004 The Apache Software Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *      http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * $Id: CountedPointer.hpp 191054 2005-06-17 02:56:35Z jberry $
 */


#if !defined(COUNTEDPOINTERTO_HPP)
#define COUNTEDPOINTERTO_HPP

#include <../../../SceneEdit/Xerces/src/xercesc/util/NullPointerException.hpp>

XERCES_CPP_NAMESPACE_BEGIN

template <class T> class CountedPointerTo : public XMemory
{
public:
    // -----------------------------------------------------------------------
    //  Constructors and Destructor
    // -----------------------------------------------------------------------
    CountedPointerTo(const CountedPointerTo<T>& toCopy);
    CountedPointerTo(T* p = 0);
    ~CountedPointerTo();


    // -----------------------------------------------------------------------
    //  Operators
    // -----------------------------------------------------------------------
    CountedPointerTo<T>& operator=(const CountedPointerTo<T>& other);
    operator T*();
    const T* operator->() const;
    T* operator->();
    const T& operator*() const;
    T& operator*();


private:
    // -----------------------------------------------------------------------
    //  Data members
    //
    //  fPtr
    //      The pointer that we are counting. The T type must implement the
    //      addRef() and removeRef() APIs but it doesn't have to derive from
    //      any particular type.
    // -----------------------------------------------------------------------
    T*  fPtr;
};

XERCES_CPP_NAMESPACE_END

#if !defined(XERCES_TMPLSINC)
#include <../../../SceneEdit/Xerces/src/xercesc/util/CountedPointer.c>
#endif

#endif
