/*
 * The Apache Software License, Version 1.1
 *
 * Copyright (c) 2001 The Apache Software Foundation.  All rights
 * reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. The end-user documentation included with the redistribution,
 *    if any, must include the following acknowledgment:
 *       "This product includes software developed by the
 *        Apache Software Foundation (http://www.apache.org/)."
 *    Alternately, this acknowledgment may appear in the software itself,
 *    if and wherever such third-party acknowledgments normally appear.
 *
 * 4. The names "Xerces" and "Apache Software Foundation" must
 *    not be used to endorse or promote products derived from this
 *    software without prior written permission. For written
 *    permission, please contact apache\@apache.org.
 *
 * 5. Products derived from this software may not be called "Apache",
 *    nor may "Apache" appear in their name, without prior written
 *    permission of the Apache Software Foundation.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESSED OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED.  IN NO EVENT SHALL THE APACHE SOFTWARE FOUNDATION OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 * ====================================================================
 *
 * This software consists of voluntary contributions made by many
 * individuals on behalf of the Apache Software Foundation, and was
 * originally based on software copyright (c) 2001, International
 * Business Machines, Inc., http://www.ibm.com .  For more information
 * on the Apache Software Foundation, please see
 * <http://www.apache.org/>.
 */

/*
 * $Id: AbstractNumericValidator.hpp,v 1.1.1.1 2002/02/01 22:22:39 peiyongz Exp $
 * $Log: AbstractNumericValidator.hpp,v $
 * Revision 1.1.1.1  2002/02/01 22:22:39  peiyongz
 * sane_include
 *
 * Revision 1.2  2001/11/22 20:23:20  peiyongz
 * _declspec(dllimport) and inline warning C4273
 *
 * Revision 1.1  2001/10/01 16:13:56  peiyongz
 * DTV Reorganization:new classes: AbstractNumericFactValidator/ AbstractNumericValidator
 *
 */

#if !defined(ABSTRACT_NUMERIC_VALIDATOR_HPP)
#define ABSTRACT_NUMERIC_VALIDATOR_HPP

#include <xercesc/validators/datatype/AbstractNumericFacetValidator.hpp>
#include <xercesc/util/RefVectorOf.hpp>
#include <xercesc/util/XMLNumber.hpp>

class VALIDATORS_EXPORT AbstractNumericValidator : public AbstractNumericFacetValidator
{
public:

    // -----------------------------------------------------------------------
    //  Public ctor/dtor
    // -----------------------------------------------------------------------
	/** @name Constructor. */
    //@{

    virtual ~AbstractNumericValidator();

	//@}

	virtual void validate(const XMLCh* const content);

protected:

    AbstractNumericValidator(DatatypeValidator*            const baseValidator
                           , RefHashTableOf<KVStringPair>* const facets
                           , const int                           finalSet
                           , const ValidatorType                 type);

    inline void init(RefVectorOf<XMLCh>*  const enums);

    //
    // Abstract interface
    //
    virtual void checkContent(const XMLCh* const content
                            , bool               asBase) = 0;

    void boundsCheck(const XMLNumber* const);

private:

    // -----------------------------------------------------------------------
    //  Private data members
    //
    // -----------------------------------------------------------------------

};

inline void AbstractNumericValidator::init(RefVectorOf<XMLCh>*  const enums)
{
    AbstractNumericFacetValidator::init(enums);
}

/**
  * End of file AbstractNumericValidator.hpp
  */
#endif