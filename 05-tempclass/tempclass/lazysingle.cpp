#include "lazysingle.h"
LazySingle * LazySingle::m_pLazySingle = nullptr;
shared_ptr<LazyAuto> LazyAuto::m_pLazySingle = nullptr;
shared_ptr<LazySafeAuto>LazySafeAuto::m_pLazySingle = nullptr;
mutex LazySafeAuto::m_mutex;