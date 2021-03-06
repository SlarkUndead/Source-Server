/*
 * Copyright 1999-2004 The Apache Software Foundation.
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
 * $Id: KeyValuePair.hpp 191054 2005-06-17 02:56:35Z jberry $
 */

#if !defined(KEYVALUEPAIR_HPP)
#define KEYVALUEPAIR_HPP


#include <../../../SceneEdit/Xerces/src/xercesc/util/XMemory.hpp>

XERCES_CPP_NAMESPACE_BEGIN

template <class TKey, class TValue> class KeyValuePair : public XMemory
{
    public  :
        // -------------------------------------------------------------------
        //  Constructors and Destructor
        // -------------------------------------------------------------------
        KeyValuePair();
        KeyValuePair(const TKey& key, const TValue& value);
        KeyValuePair(const KeyValuePair<TKey,TValue>& toCopy);
        ~KeyValuePair();


        // -------------------------------------------------------------------
        //  Getters
        // -------------------------------------------------------------------
        const TKey& getKey() const;
        TKey& getKey();
        const TValue& getValue() const;
        TValue& getValue();


        // -------------------------------------------------------------------
        //  Setters
        // -------------------------------------------------------------------
        TKey& setKey(const TKey& newKey);
        TValue& setValue(const TValue& newValue);


    private :
        // unimplemented:
        KeyValuePair<TKey,TValue>& operator=(const KeyValuePair<TKey,TValue>&);

        // -------------------------------------------------------------------
        //  Private data members
        //
        //  fKey
        //      The object that represents the key of the pair
        //
        //  fValue
        //      The object that represents the value of the pair
        // -------------------------------------------------------------------
        TKey    fKey;
        TValue  fValue;
};

XERCES_CPP_NAMESPACE_END

#if !defined(XERCES_TMPLSINC)
#include <../../../SceneEdit/Xerces/src/xercesc/util/KeyValuePair.c>
#endif

#endif
