#include "fields.hpp"

namespace lvzheng {
namespace fixme {

const std::unordered_map<unsigned, std::string> field_str {
	{1, "Account"},
	{2, "AdvId"},
	{3, "AdvRefID"},
	{4, "AdvSide"},
	{5, "AdvTransType"},
	{6, "AvgPx"},
	{7, "BeginSeqNo"},
	{8, "BeginString"},
	{9, "BodyLength"},
	{10, "CheckSum"},
	{11, "ClOrdID"},
	{12, "Commission"},
	{13, "CommType"},
	{14, "CumQty"},
	{15, "Currency"},
	{16, "EndSeqNo"},
	{17, "ExecID"},
	{18, "ExecInst"},
	{19, "ExecRefID"},
	{20, "ExecTransType"},
	{21, "HandlInst"},
	{22, "IDSource"},
	{23, "IOIid"},
	{24, "IOIOthSvc (no longer used)"},
	{25, "IOIQltyInd"},
	{26, "IOIRefID"},
	{27, "IOIShares"},
	{28, "IOITransType"},
	{29, "LastCapacity"},
	{30, "LastMkt"},
	{31, "LastPx"},
	{32, "LastShares"},
	{33, "LinesOfText"},
	{34, "MsgSeqNum"},
	{35, "MsgType"},
	{36, "NewSeqNo"},
	{37, "OrderID"},
	{38, "OrderQty"},
	{39, "OrdStatus"},
	{40, "OrdType"},
	{41, "OrigClOrdID"},
	{42, "OrigTime"},
	{43, "PossDupFlag"},
	{44, "Price"},
	{45, "RefSeqNum"},
	{46, "RelatdSym"},
	{47, "Rule80A(aka OrderCapacity)"},
	{48, "SecurityID"},
	{49, "SenderCompID"},
	{50, "SenderSubID"},
	{51, "SendingDate (no longer used)"},
	{52, "SendingTime"},
	{53, "Shares"},
	{54, "Side"},
	{55, "Symbol"},
	{56, "TargetCompID"},
	{57, "TargetSubID"},
	{58, "Text"},
	{59, "TimeInForce"},
	{60, "TransactTime"},
	{61, "Urgency"},
	{62, "ValidUntilTime"},
	{63, "SettlmntTyp"},
	{64, "FutSettDate"},
	{65, "SymbolSfx"},
	{66, "ListID"},
	{67, "ListSeqNo"},
	{68, "TotNoOrders(formerly named: ListNoOrds)"},
	{69, "ListExecInst"},
	{70, "AllocID"},
	{71, "AllocTransType"},
	{72, "RefAllocID"},
	{73, "NoOrders"},
	{74, "AvgPrxPrecision"},
	{75, "TradeDate"},
	{76, "ExecBroker"},
	{77, "OpenClose"},
	{78, "NoAllocs"},
	{79, "AllocAccount"},
	{80, "AllocShares"},
	{81, "ProcessCode"},
	{82, "NoRpts"},
	{83, "RptSeq"},
	{84, "CxlQty"},
	{85, "NoDlvyInst(no longer used)"},
	{86, "DlvyInst(no longer used)"},
	{87, "AllocStatus"},
	{88, "AllocRejCode"},
	{89, "Signature"},
	{90, "SecureDataLen"},
	{91, "SecureData"},
	{92, "BrokerOfCredit"},
	{93, "SignatureLength"},
	{94, "EmailType"},
	{95, "RawDataLength"},
	{96, "RawData"},
	{97, "PossResend"},
	{98, "EncryptMethod"},
	{99, "StopPx"},
	{100, "ExDestination"},
	{102, "CxlRejReason"},
	{103, "OrdRejReason"},
	{104, "IOIQualifier"},
	{105, "WaveNo"},
	{106, "Issuer"},
	{107, "SecurityDesc"},
	{108, "HeartBtInt"},
	{109, "ClientID"},
	{110, "MinQty"},
	{111, "MaxFloor"},
	{112, "TestReqID"},
	{113, "ReportToExch"},
	{114, "LocateReqd"},
	{115, "OnBehalfOfCompID"},
	{116, "OnBehalfOfSubID"},
	{117, "QuoteID"},
	{118, "NetMoney"},
	{119, "SettlCurrAmt"},
	{120, "SettlCurrency"},
	{121, "ForexReq"},
	{122, "OrigSendingTime"},
	{123, "GapFillFlag"},
	{124, "NoExecs"},
	{125, "CxlType(no longer used)"},
	{126, "ExpireTime"},
	{127, "DKReason"},
	{128, "DeliverToCompID"},
	{129, "DeliverToSubID"},
	{130, "IOINaturalFlag"},
	{131, "QuoteReqID"},
	{132, "BidPx"},
	{133, "OfferPx"},
	{134, "BidSize"},
	{135, "OfferSize"},
	{136, "NoMiscFees"},
	{137, "MiscFeeAmt"},
	{138, "MiscFeeCurr"},
	{139, "MiscFeeType"},
	{140, "PrevClosePx"},
	{141, "ResetSeqNumFlag"},
	{142, "SenderLocationID"},
	{143, "TargetLocationID"},
	{144, "OnBehalfOfLocationID"},
	{145, "DeliverToLocationID"},
	{146, "NoRelatedSym"},
	{147, "Subject"},
	{148, "Headline"},
	{149, "URLLink"},
	{150, "ExecType"},
	{151, "LeavesQty"},
	{152, "CashOrderQty"},
	{153, "AllocAvgPx"},
	{154, "AllocNetMoney"},
	{155, "SettlCurrFxRate"},
	{156, "SettlCurrFxRateCalc"},
	{157, "NumDaysInterest"},
	{158, "AccruedInterestRate"},
	{159, "AccruedInterestAmt"},
	{160, "SettlInstMode"},
	{161, "AllocText"},
	{162, "SettlInstID"},
	{163, "SettlInstTransType"},
	{164, "EmailThreadID"},
	{165, "SettlInstSource"},
	{166, "SettlLocation"},
	{167, "SecurityType"},
	{168, "EffectiveTime"},
	{169, "StandInstDbType"},
	{170, "StandInstDbName"},
	{171, "StandInstDbID"},
	{172, "SettlDeliveryType"},
	{173, "SettlDepositoryCode"},
	{174, "SettlBrkrCode"},
	{175, "SettlInstCode"},
	{176, "SecuritySettlAgentName"},
	{177, "SecuritySettlAgentCode"},
	{178, "SecuritySettlAgentAcctNum"},
	{179, "SecuritySettlAgentAcctName"},
	{180, "SecuritySettlAgentContactName"},
	{181, "SecuritySettlAgentContactPhone"},
	{182, "CashSettlAgentName"},
	{183, "CashSettlAgentCode"},
	{184, "CashSettlAgentAcctNum"},
	{185, "CashSettlAgentAcctName"},
	{186, "CashSettlAgentContactName"},
	{187, "CashSettlAgentContactPhone"},
	{188, "BidSpotRate"},
	{189, "BidForwardPoints"},
	{190, "OfferSpotRate"},
	{191, "OfferForwardPoints"},
	{192, "OrderQty2"},
	{193, "FutSettDate2"},
	{194, "LastSpotRate"},
	{195, "LastForwardPoints"},
	{196, "AllocLinkID"},
	{197, "AllocLinkType"},
	{198, "SecondaryOrderID"},
	{199, "NoIOIQualifiers"},
	{200, "MaturityMonthYear"},
	{201, "PutOrCall"},
	{202, "StrikePrice"},
	{203, "CoveredOrUncovered"},
	{204, "CustomerOrFirm"},
	{205, "MaturityDay"},
	{206, "OptAttribute"},
	{207, "SecurityExchange"},
	{208, "NotifyBrokerOfCredit"},
	{209, "AllocHandlInst"},
	{210, "MaxShow"},
	{211, "PegDifference"},
	{212, "XmlDataLen"},
	{213, "XmlData"},
	{214, "SettlInstRefID"},
	{215, "NoRoutingIDs"},
	{216, "RoutingType"},
	{217, "RoutingID"},
	{218, "SpreadToBenchmark"},
	{219, "Benchmark"},
	{223, "CouponRate"},
	{231, "ContractMultiplier"},
	{262, "MDReqID"},
	{263, "SubscriptionRequestType"},
	{264, "MarketDepth"},
	{265, "MDUpdateType"},
	{266, "AggregatedBook"},
	{267, "NoMDEntryTypes"},
	{268, "NoMDEntries"},
	{269, "MDEntryType"},
	{270, "MDEntryPx"},
	{271, "MDEntrySize"},
	{272, "MDEntryDate"},
	{273, "MDEntryTime"},
	{274, "TickDirection"},
	{275, "MDMkt"},
	{276, "QuoteCondition"},
	{277, "TradeCondition"},
	{278, "MDEntryID"},
	{279, "MDUpdateAction"},
	{280, "MDEntryRefID"},
	{281, "MDReqRejReason"},
	{282, "MDEntryOriginator"},
	{283, "LocationID"},
	{284, "DeskID"},
	{285, "DeleteReason"},
	{286, "OpenCloseSettleFlag"},
	{287, "SellerDays"},
	{288, "MDEntryBuyer"},
	{289, "MDEntrySeller"},
	{290, "MDEntryPositionNo"},
	{291, "FinancialStatus"},
	{292, "CorporateAction"},
	{293, "DefBidSize"},
	{294, "DefOfferSize"},
	{295, "NoQuoteEntries"},
	{296, "NoQuoteSets"},
	{297, "QuoteAckStatus"},
	{298, "QuoteCancelType"},
	{299, "QuoteEntryID"},
	{300, "QuoteRejectReason"},
	{301, "QuoteResponseLevel"},
	{302, "QuoteSetID"},
	{303, "QuoteRequestType"},
	{304, "TotQuoteEntries"},
	{305, "UnderlyingIDSource"},
	{306, "UnderlyingIssuer"},
	{307, "UnderlyingSecurityDesc"},
	{308, "UnderlyingSecurityExchange"},
	{309, "UnderlyingSecurityID"},
	{310, "UnderlyingSecurityType"},
	{311, "UnderlyingSymbol"},
	{312, "UnderlyingSymbolSfx"},
	{313, "UnderlyingMaturityMonthYear"},
	{314, "UnderlyingMaturityDay"},
	{315, "UnderlyingPutOrCall"},
	{316, "UnderlyingStrikePrice"},
	{317, "UnderlyingOptAttribute"},
	{318, "Underlying Currency"},
	{319, "RatioQty"},
	{320, "SecurityReqID"},
	{321, "SecurityRequestType"},
	{322, "SecurityResponseID"},
	{323, "SecurityResponseType"},
	{324, "SecurityStatusReqID"},
	{325, "UnsolicitedIndicator"},
	{326, "SecurityTradingStatus"},
	{327, "HaltReason"},
	{328, "InViewOfCommon"},
	{329, "DueToRelated"},
	{330, "BuyVolume"},
	{331, "SellVolume"},
	{332, "HighPx"},
	{333, "LowPx"},
	{334, "Adjustment"},
	{335, "TradSesReqID"},
	{336, "TradingSessionID"},
	{337, "ContraTrader"},
	{338, "TradSesMethod"},
	{339, "TradSesMode"},
	{340, "TradSesStatus"},
	{341, "TradSesStartTime"},
	{342, "TradSesOpenTime"},
	{343, "TradSesPreCloseTime"},
	{344, "TradSesCloseTime"},
	{345, "TradSesEndTime"},
	{346, "NumberOfOrders"},
	{347, "MessageEncoding"},
	{348, "EncodedIssuerLen"},
	{349, "EncodedIssuer"},
	{350, "EncodedSecurityDescLen"},
	{351, "EncodedSecurityDesc"},
	{352, "EncodedListExecInstLen"},
	{353, "EncodedListExecInst"},
	{354, "EncodedTextLen"},
	{355, "EncodedText"},
	{356, "EncodedSubjectLen"},
	{357, "EncodedSubject"},
	{358, "EncodedHeadlineLen"},
	{359, "EncodedHeadline"},
	{360, "EncodedAllocTextLen"},
	{361, "EncodedAllocText"},
	{362, "EncodedUnderlyingIssuerLen"},
	{363, "EncodedUnderlyingIssuer"},
	{364, "EncodedUnderlyingSecurityDescLen"},
	{365, "EncodedUnderlyingSecurityDesc"},
	{366, "AllocPrice"},
	{367, "QuoteSetValidUntilTime"},
	{368, "QuoteEntryRejectReason"},
	{369, "LastMsgSeqNumProcessed"},
	{370, "OnBehalfOfSendingTime"},
	{371, "RefTagID"},
	{372, "RefMsgType"},
	{373, "SessionRejectReason"},
	{374, "BidRequestTransType"},
	{375, "ContraBroker"},
	{376, "ComplianceID"},
	{377, "SolicitedFlag"},
	{378, "ExecRestatementReason"},
	{379, "BusinessRejectRefID"},
	{380, "BusinessRejectReason"},
	{381, "GrossTradeAmt"},
	{382, "NoContraBrokers"},
	{383, "MaxMessageSize"},
	{384, "NoMsgTypes"},
	{385, "MsgDirection"},
	{386, "NoTradingSessions"},
	{387, "TotalVolumeTraded"},
	{388, "DiscretionInst"},
	{389, "DiscretionOffset"},
	{390, "BidID"},
	{391, "ClientBidID"},
	{392, "ListName"},
	{393, "TotalNumSecurities"},
	{394, "BidType"},
	{395, "NumTickets"},
	{396, "SideValue1"},
	{397, "SideValue2"},
	{398, "NoBidDescriptors"},
	{399, "BidDescriptorType"},
	{400, "BidDescriptor"},
	{401, "SideValueInd"},
	{402, "LiquidityPctLow"},
	{403, "LiquidityPctHigh"},
	{404, "LiquidityValue"},
	{405, "EFPTrackingError"},
	{406, "FairValue"},
	{407, "OutsideIndexPct"},
	{408, "ValueOfFutures"},
	{409, "LiquidityIndType"},
	{410, "WtAverageLiquidity"},
	{411, "ExchangeForPhysical"},
	{412, "OutMainCntryUIndex"},
	{413, "CrossPercent"},
	{414, "ProgRptReqs"},
	{415, "ProgPeriodInterval"},
	{416, "IncTaxInd"},
	{417, "NumBidders"},
	{418, "TradeType"},
	{419, "BasisPxType"},
	{420, "NoBidComponents"},
	{421, "Country"},
	{422, "TotNoStrikes"},
	{423, "PriceType"},
	{424, "DayOrderQty"},
	{425, "DayCumQty"},
	{426, "DayAvgPx"},
	{427, "GTBookingInst"},
	{428, "NoStrikes"},
	{429, "ListStatusType"},
	{430, "NetGrossInd"},
	{431, "ListOrderStatus"},
	{432, "ExpireDate"},
	{433, "ListExecInstType"},
	{434, "CxlRejResponseTo"},
	{435, "UnderlyingCouponRate"},
	{436, "UnderlyingContractMultiplier"},
	{437, "ContraTradeQty"},
	{438, "ContraTradeTime"},
	{439, "ClearingFirm"},
	{440, "ClearingAccount"},
	{441, "LiquidityNumSecurities"},
	{442, "MultiLegReportingType"},
	{443, "StrikeTime"},
	{444, "ListStatusText"},
	{445, "EncodedListStatusTextLen"},
	{446, "EncodedListStatusText"},
};

} } // namespace lvzheng::fixme