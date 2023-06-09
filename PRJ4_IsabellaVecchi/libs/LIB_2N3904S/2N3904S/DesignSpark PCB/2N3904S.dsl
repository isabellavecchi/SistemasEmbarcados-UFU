SamacSys ECAD Model
16529493/918037/2.49/3/3/Transistor BJT NPN

DESIGNSPARK_INTERMEDIATE_ASCII

(asciiHeader
	(fileUnits MM)
)
(library Library_1
	(padStyleDef "r95_70"
		(holeDiam 0)
		(padShape (layerNumRef 1) (padShapeType Rect)  (shapeWidth 0.7) (shapeHeight 0.95))
		(padShape (layerNumRef 16) (padShapeType Ellipse)  (shapeWidth 0) (shapeHeight 0))
	)
	(textStyleDef "Default"
		(font
			(fontType Stroke)
			(fontFace "Helvetica")
			(fontHeight 50 mils)
			(strokeWidth 5 mils)
		)
	)
	(patternDef "SOT95P245X130-3N" (originalName "SOT95P245X130-3N")
		(multiLayer
			(pad (padNum 1) (padStyleRef r95_70) (pt -1.25, 0.95) (rotation 90))
			(pad (padNum 2) (padStyleRef r95_70) (pt -1.25, -0.95) (rotation 90))
			(pad (padNum 3) (padStyleRef r95_70) (pt 1.25, 0) (rotation 90))
		)
		(layerContents (layerNumRef 18)
			(attr "RefDes" "RefDes" (pt 0, 0) (textStyleRef "Default") (isVisible True))
		)
		(layerContents (layerNumRef 30)
			(line (pt -1.975 1.815) (pt 1.975 1.815) (width 0.05))
		)
		(layerContents (layerNumRef 30)
			(line (pt 1.975 1.815) (pt 1.975 -1.815) (width 0.05))
		)
		(layerContents (layerNumRef 30)
			(line (pt 1.975 -1.815) (pt -1.975 -1.815) (width 0.05))
		)
		(layerContents (layerNumRef 30)
			(line (pt -1.975 -1.815) (pt -1.975 1.815) (width 0.05))
		)
		(layerContents (layerNumRef 28)
			(line (pt -0.662 1.465) (pt 0.662 1.465) (width 0.1))
		)
		(layerContents (layerNumRef 28)
			(line (pt 0.662 1.465) (pt 0.662 -1.465) (width 0.1))
		)
		(layerContents (layerNumRef 28)
			(line (pt 0.662 -1.465) (pt -0.662 -1.465) (width 0.1))
		)
		(layerContents (layerNumRef 28)
			(line (pt -0.662 -1.465) (pt -0.662 1.465) (width 0.1))
		)
		(layerContents (layerNumRef 28)
			(line (pt -0.662 0.515) (pt 0.288 1.465) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(line (pt -0.425 1.465) (pt 0.425 1.465) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt 0.425 1.465) (pt 0.425 -1.465) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt 0.425 -1.465) (pt -0.425 -1.465) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt -0.425 -1.465) (pt -0.425 1.465) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt -1.725 1.55) (pt -0.775 1.55) (width 0.2))
		)
	)
	(symbolDef "2N3904S" (originalName "2N3904S")

		(pin (pinNum 1) (pt 0 mils 0 mils) (rotation 0) (pinLength 100 mils) (pinDisplay (dispPinName false)) (pinName (text (pt 0 mils -45 mils) (rotation 0]) (justify "UpperLeft") (textStyleRef "Default"))
		))
		(pin (pinNum 2) (pt 400 mils -300 mils) (rotation 90) (pinLength 100 mils) (pinDisplay (dispPinName false)) (pinName (text (pt 405 mils -300 mils) (rotation 90]) (justify "LowerLeft") (textStyleRef "Default"))
		))
		(pin (pinNum 3) (pt 400 mils 300 mils) (rotation 270) (pinLength 100 mils) (pinDisplay (dispPinName false)) (pinName (text (pt 405 mils 300 mils) (rotation 90]) (justify "UpperLeft") (textStyleRef "Default"))
		))
		(line (pt 300 mils 100 mils) (pt 300 mils -100 mils) (width 20 mils))
		(line (pt 300 mils 50 mils) (pt 400 mils 150 mils) (width 6 mils))
		(line (pt 300 mils -50 mils) (pt 400 mils -150 mils) (width 6 mils))
		(line (pt 400 mils -150 mils) (pt 400 mils -200 mils) (width 6 mils))
		(line (pt 400 mils 150 mils) (pt 400 mils 200 mils) (width 6 mils))
		(line (pt 100 mils 0 mils) (pt 300 mils 0 mils) (width 6 mils))
		(arc (pt 350 mils 0 mils) (radius 158.114 mils) (startAngle 0) (sweepAngle 360) (width 10  mils))
		(poly (pt 330 mils -100 mils) (pt 350 mils -80 mils) (pt 370 mils -120 mils) (pt 330 mils -100 mils) (width 10  mils))
		(attr "RefDes" "RefDes" (pt 550 mils 50 mils) (justify Left) (isVisible True) (textStyleRef "Default"))

	)
	(compDef "2N3904S" (originalName "2N3904S") (compHeader (numPins 3) (numParts 1) (refDesPrefix Q)
		)
		(compPin "1" (pinName "E") (partNum 1) (symPinNum 2) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "2" (pinName "B") (partNum 1) (symPinNum 1) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "3" (pinName "C") (partNum 1) (symPinNum 3) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(attachedSymbol (partNum 1) (altType Normal) (symbolName "2N3904S"))
		(attachedPattern (patternNum 1) (patternName "SOT95P245X130-3N")
			(numPads 3)
			(padPinMap
				(padNum 1) (compPinRef "1")
				(padNum 2) (compPinRef "2")
				(padNum 3) (compPinRef "3")
			)
		)
		(attr "Manufacturer_Name" "KEC")
		(attr "Manufacturer_Part_Number" "2N3904S")
		(attr "Mouser Part Number" "")
		(attr "Mouser Price/Stock" "")
		(attr "Arrow Part Number" "")
		(attr "Arrow Price/Stock" "")
		(attr "Description" "x")
		(attr "Datasheet Link" "https://4donline.ihs.com/images/VipMasterIC/IC/KECC/KECC-S-A0011628560/KECC-S-A0011628560-1.pdf?hkey=EF798316E3902B6ED9A73243A3159BB0")
		(attr "Height" "1.3 mm")
	)

)
