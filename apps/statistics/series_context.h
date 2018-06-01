#ifndef STATISTICS_SERIES_CONTEXT_H
#define STATISTICS_SERIES_CONTEXT_H

#include <poincare/context.h>
#include "../shared/float_pair_store.h"

namespace Statistics {

class SeriesContext : public Poincare::Context {
public:
  SeriesContext(Shared::FloatPairStore * store, Poincare::Context * parentContext = nullptr) :
    Poincare::Context(),
    m_store(store),
    m_seriesPairIndex(-1),
    m_parentContext(parentContext)
  {}
  void setSeriesPairIndex(int j) { m_seriesPairIndex = j; }
  void setExpressionForSymbolName(const Poincare::Expression * expression, const Poincare::Symbol * symbol, Poincare::Context & context) override;
  const Poincare::Expression * expressionForSymbol(const Poincare::Symbol * symbol) override;
private:
  Shared::FloatPairStore * m_store;
  int m_seriesPairIndex;
  Poincare::Context * m_parentContext;
};

}

#endif
