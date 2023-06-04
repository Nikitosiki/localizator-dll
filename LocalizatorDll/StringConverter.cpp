//#include <iostream>
//#include <string>
//#include <iconv.h>
//#include <codecvt>
//#include "StringConverter.h"
//#include <locale>
//#include <codecvt>

//const std::string StringConverter::ConvertUtf8ToAnsi(const std::string& input)
//{
//    using wcvt = std::wstring_convert<std::codecvt_utf8<int32_t>, int32_t>;
//    auto wstr = wcvt{}.from_bytes(input);
//    std::string result(wstr.size(), '0');
//    std::use_facet<std::ctype<char32_t>>(std::locale{}).narrow(
//        reinterpret_cast<const char32_t*>(wstr.data()),
//        reinterpret_cast<const char32_t*>(wstr.data() + wstr.size()),
//        '?', &result[0]);
//    return result;
//}

//std::string to_utf8(const std::string& str, const std::locale& loc = std::locale{}) {
//    using wcvt = std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t>;
//    std::u32string wstr(str.size(), U'\0');
//    std::use_facet<std::ctype<char32_t>>(loc).widen(str.data(), str.data() + str.size(), &wstr[0]);
//    return wcvt{}.to_bytes(wstr.data(), wstr.data() + wstr.size());
//}

//const std::string StringConverter::ConvertAnsiToUtf8(const std::string& input)
//{
//    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
//    std::wstring wideStr = converter.from_bytes(input);
//    return std::string(wideStr.begin(), wideStr.end());
//}