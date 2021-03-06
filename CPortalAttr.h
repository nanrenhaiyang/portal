/**
* Copyright (c) 2015, 爱wifi（版权声明）
*
* @file xxxxxxx
* @brief 文件的简单介绍
*
* 文件的详细介绍
*
* @author: yuhaiyang
* @date: 2016/4/7
*/

#ifndef CPORTALATTR_H
#define CPORTALATTR_H

#include <string>
#include "PortalCommon.h"

namespace Taiji {


class CPortalAttr
{
public:
    typedef std::map< EATTR_TYPE, std::string> AttrType2Str;

public:
    CPortalAttr() = default;
    ~CPortalAttr() = default;

    //给 stl vector 用的
    CPortalAttr( const CPortalAttr& other );

    CPortalAttr( EATTR_TYPE type, const std::string& val );
    CPortalAttr( EATTR_TYPE type, const HexType& val );

    EATTR_TYPE type() const;
    void setType(const EATTR_TYPE &type);
    std::string getTypeStr( void );

    uint8_t length() const;

    std::string val() const;
    void setVal(const std::string &val);
    void setVal(const HexType &val);

    const HexType& pack( void );

    void unpack( const HexType& data );

//    void printHex();
private:
    //数据包类型与对应的字符串
    static AttrType2Str _typeStr;
    struct SAttrHead
    {
        EATTR_TYPE _type = EATTR_TYPE::NONE; 	///< 包类型
        uint8_t _length = 0;              		///< 长度
    } _head;
    std::string _val = "";              	///< 数据段
    HexType _data;							///< 网络数据包
};



}

#endif // CPORTALATTR_H



