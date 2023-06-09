PULSONIX_LIBRARY_ASCII "SamacSys ECAD Model"
//1053345/918037/2.49/2/4/Capacitor Polarised

(asciiHeader
	(fileUnits MM)
)
(library Library_1
	(padStyleDef "r150_135"
		(holeDiam 0)
		(padShape (layerNumRef 1) (padShapeType Rect)  (shapeWidth 1.350) (shapeHeight 1.500))
		(padShape (layerNumRef 16) (padShapeType Ellipse)  (shapeWidth 0) (shapeHeight 0))
	)
	(textStyleDef "Normal"
		(font
			(fontType Stroke)
			(fontFace "Helvetica")
			(fontHeight 1.27)
			(strokeWidth 0.127)
		)
	)
	(patternDef "TMCMA0G107MTRF" (originalName "TMCMA0G107MTRF")
		(multiLayer
			(pad (padNum 1) (padStyleRef r150_135) (pt -1.225, 0.000) (rotation 0))
			(pad (padNum 2) (padStyleRef r150_135) (pt 1.225, 0.000) (rotation 0))
		)
		(layerContents (layerNumRef 18)
			(attr "RefDes" "RefDes" (pt -0.000, 0.000) (textStyleRef "Normal") (isVisible True))
		)
		(layerContents (layerNumRef 28)
			(line (pt -1.6 0.8) (pt 1.6 0.8) (width 0.025))
		)
		(layerContents (layerNumRef 28)
			(line (pt 1.6 0.8) (pt 1.6 -0.8) (width 0.025))
		)
		(layerContents (layerNumRef 28)
			(line (pt 1.6 -0.8) (pt -1.6 -0.8) (width 0.025))
		)
		(layerContents (layerNumRef 28)
			(line (pt -1.6 -0.8) (pt -1.6 0.8) (width 0.025))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt -2.9 1.8) (pt 2.9 1.8) (width 0.1))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt 2.9 1.8) (pt 2.9 -1.8) (width 0.1))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt 2.9 -1.8) (pt -2.9 -1.8) (width 0.1))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt -2.9 -1.8) (pt -2.9 1.8) (width 0.1))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt -2.9 1.8) (pt 2.9 1.8) (width 0.1))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt 2.9 1.8) (pt 2.9 -1.8) (width 0.1))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt 2.9 -1.8) (pt -2.9 -1.8) (width 0.1))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt -2.9 -1.8) (pt -2.9 1.8) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(line (pt -2.6 0) (pt -2.6 0) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(arc (pt -2.55, 0) (radius 0.05) (startAngle 180.0) (sweepAngle 180.0) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(line (pt -2.5 0) (pt -2.5 0) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(arc (pt -2.55, 0) (radius 0.05) (startAngle .0) (sweepAngle 180.0) (width 0.1))
		)
	)
	(symbolDef "TMCMA0G107MTRF" (originalName "TMCMA0G107MTRF")

		(pin (pinNum 1) (pt 0 mils 0 mils) (rotation 0) (pinLength 100 mils) (pinDisplay (dispPinName false)) (pinName (text (pt 0 mils -35 mils) (rotation 0]) (justify "UpperLeft") (textStyleRef "Normal"))
		))
		(pin (pinNum 2) (pt 500 mils 0 mils) (rotation 180) (pinLength 100 mils) (pinDisplay (dispPinName false)) (pinName (text (pt 500 mils -35 mils) (rotation 0]) (justify "UpperRight") (textStyleRef "Normal"))
		))
		(line (pt 200 mils 100 mils) (pt 200 mils -100 mils) (width 6 mils))
		(line (pt 200 mils -100 mils) (pt 230 mils -100 mils) (width 6 mils))
		(line (pt 230 mils -100 mils) (pt 230 mils 100 mils) (width 6 mils))
		(line (pt 230 mils 100 mils) (pt 200 mils 100 mils) (width 6 mils))
		(line (pt 180 mils 50 mils) (pt 140 mils 50 mils) (width 6 mils))
		(line (pt 160 mils 70 mils) (pt 160 mils 30 mils) (width 6 mils))
		(line (pt 100 mils 0 mils) (pt 200 mils 0 mils) (width 6 mils))
		(line (pt 300 mils 0 mils) (pt 400 mils 0 mils) (width 6 mils))
		(poly (pt 300 mils 100 mils) (pt 300 mils -100 mils) (pt 270 mils -100 mils) (pt 270 mils 100 mils) (pt 300 mils 100 mils) (width 10  mils))
		(attr "RefDes" "RefDes" (pt 350 mils 250 mils) (justify 24) (isVisible True) (textStyleRef "Normal"))
		(attr "Type" "Type" (pt 350 mils 150 mils) (justify 24) (isVisible True) (textStyleRef "Normal"))

	)
	(compDef "TMCMA0G107MTRF" (originalName "TMCMA0G107MTRF") (compHeader (numPins 2) (numParts 1) (refDesPrefix C)
		)
		(compPin "1" (pinName "+") (partNum 1) (symPinNum 1) (gateEq 0) (pinEq 0) (pinType Unknown))
		(compPin "2" (pinName "-") (partNum 1) (symPinNum 2) (gateEq 0) (pinEq 0) (pinType Unknown))
		(attachedSymbol (partNum 1) (altType Normal) (symbolName "TMCMA0G107MTRF"))
		(attachedPattern (patternNum 1) (patternName "TMCMA0G107MTRF")
			(numPads 2)
			(padPinMap
				(padNum 1) (compPinRef "1")
				(padNum 2) (compPinRef "2")
			)
		)
		(attr "Manufacturer_Name" "Vishay")
		(attr "Manufacturer_Part_Number" "TMCMA0G107MTRF")
		(attr "Mouser Part Number" "74-TMCMA0G107MTRF")
		(attr "Mouser Price/Stock" "https://www.mouser.co.uk/ProductDetail/Vishay-Sprague/TMCMA0G107MTRF?qs=NgbZBzc1CyFRT2%252B5t9x4xw%3D%3D")
		(attr "Arrow Part Number" "")
		(attr "Arrow Price/Stock" "")
		(attr "Description" "Tantalum Capacitors - Solid SMD 100uF 4V 20% A case")
		(attr "<Hyperlink>" "https://componentsearchengine.com/Datasheets/1/TMCMA0G107MTRF.pdf")
		(attr "<Component Height>" "1.8")
		(attr "<STEP Filename>" "TMCMA0G107MTRF.stp")
		(attr "<STEP Offsets>" "X=0;Y=0;Z=0")
		(attr "<STEP Rotation>" "X=0;Y=0;Z=0")
	)

)
