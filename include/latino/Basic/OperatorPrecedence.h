//===----------------------------------------------------------------------===//
///
/// \file
/// Defines and computes precedence levels for binary/ternary operators.
///
//===----------------------------------------------------------------------===//
#ifndef LATINO_BASIC_OPERATORPRECEDENCE_H
#define LATINO_BASIC_OPERATORPRECEDENCE_H

#include "latino/Basic/TokenKinds.h"

namespace latino {
/// PrecedenceLevels - These are precedences for the binary/ternary
/// operators in the C99 grammar.  These have been named to relate
/// with the C99 grammar productions.  Low precedences numbers bind
/// more weakly than high numbers.
namespace prec {
enum Level {
  Unknown = 0,         // Not binary operator.
  Comma = 1,           // ,
  Assignment = 2,      // =, *=, /=, %=, +=, -=, <<=, >>=, &=, ^=, |=
  Conditional = 3,     // ?
  LogicalOr = 4,       // ||
  LogicalAnd = 5,      // &&
  InclusiveOr = 6,     // |
  ExclusiveOr = 7,     // ^
  And = 8,             // &
  Equality = 9,        // ==, !=
  Relational = 10,     //  >=, <=, >, <
  Spaceship = 11,      // <=>
  Shift = 12,          // <<, >>
  Additive = 13,       // -, +
  Multiplicative = 14, // *, /, %
  PointerToMember = 15 // .*, ->*
};
} /* namespace prec */

/// Return the precedence of the specified binary operator token.
prec::Level getBinOpPrecedence(tok::TokenKind Kind, bool GreaterThanIsOperator,
                               bool CPlusPlus11);

} /* namespace latino */

#endif /* LATINO_BASIC_OPERATORPRECEDENCE_H */
