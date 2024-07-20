<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.7.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="2" name="Route2" color="16" fill="1" visible="no" active="no"/>
<layer number="3" name="Route3" color="17" fill="1" visible="no" active="no"/>
<layer number="4" name="Route4" color="18" fill="1" visible="no" active="no"/>
<layer number="5" name="Route5" color="19" fill="1" visible="no" active="no"/>
<layer number="6" name="Route6" color="25" fill="1" visible="no" active="no"/>
<layer number="7" name="Route7" color="26" fill="1" visible="no" active="no"/>
<layer number="8" name="Route8" color="27" fill="1" visible="no" active="no"/>
<layer number="9" name="Route9" color="28" fill="1" visible="no" active="no"/>
<layer number="10" name="Route10" color="29" fill="1" visible="no" active="no"/>
<layer number="11" name="Route11" color="30" fill="1" visible="no" active="no"/>
<layer number="12" name="Route12" color="20" fill="1" visible="no" active="no"/>
<layer number="13" name="Route13" color="21" fill="1" visible="no" active="no"/>
<layer number="14" name="Route14" color="22" fill="1" visible="no" active="no"/>
<layer number="15" name="Route15" color="23" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="24" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="88" name="SimResults" color="9" fill="1" visible="yes" active="yes"/>
<layer number="89" name="SimProbes" color="9" fill="1" visible="yes" active="yes"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
<layer number="99" name="SpiceOrder" color="7" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="Connector">
<description>&lt;b&gt;Pin Headers,Terminal blocks, D-Sub, Backplane, FFC/FPC, Socket</description>
<packages>
<package name="1X08" urn="urn:adsk.eagle:footprint:22262/1">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="5.715" y1="1.27" x2="6.985" y2="1.27" width="0.1524" layer="21"/>
<wire x1="6.985" y1="1.27" x2="7.62" y2="0.635" width="0.1524" layer="21"/>
<wire x1="7.62" y1="0.635" x2="7.62" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="7.62" y1="-0.635" x2="6.985" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="2.54" y1="0.635" x2="3.175" y2="1.27" width="0.1524" layer="21"/>
<wire x1="3.175" y1="1.27" x2="4.445" y2="1.27" width="0.1524" layer="21"/>
<wire x1="4.445" y1="1.27" x2="5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="5.08" y1="0.635" x2="5.08" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="5.08" y1="-0.635" x2="4.445" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="4.445" y1="-1.27" x2="3.175" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="3.175" y1="-1.27" x2="2.54" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="5.715" y1="1.27" x2="5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="5.08" y1="-0.635" x2="5.715" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="6.985" y1="-1.27" x2="5.715" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="1.27" x2="-0.635" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="1.27" x2="0" y2="0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="0.635" x2="0" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="-0.635" x2="-0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="0" y1="0.635" x2="0.635" y2="1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="1.27" x2="1.905" y2="1.27" width="0.1524" layer="21"/>
<wire x1="1.905" y1="1.27" x2="2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="0.635" x2="2.54" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="-0.635" x2="1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="1.905" y1="-1.27" x2="0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-1.27" x2="0" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="0.635" x2="-4.445" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="1.27" x2="-3.175" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="1.27" x2="-2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="0.635" x2="-2.54" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="-0.635" x2="-3.175" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="-1.27" x2="-4.445" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="-1.27" x2="-5.08" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="1.27" x2="-2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="-0.635" x2="-1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="-1.27" x2="-1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-9.525" y1="1.27" x2="-8.255" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-8.255" y1="1.27" x2="-7.62" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="0.635" x2="-7.62" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="-0.635" x2="-8.255" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="0.635" x2="-6.985" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-6.985" y1="1.27" x2="-5.715" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-5.715" y1="1.27" x2="-5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="0.635" x2="-5.08" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="-0.635" x2="-5.715" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-5.715" y1="-1.27" x2="-6.985" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-6.985" y1="-1.27" x2="-7.62" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="0.635" x2="-10.16" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-9.525" y1="1.27" x2="-10.16" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="-0.635" x2="-9.525" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-8.255" y1="-1.27" x2="-9.525" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="8.255" y1="1.27" x2="9.525" y2="1.27" width="0.1524" layer="21"/>
<wire x1="9.525" y1="1.27" x2="10.16" y2="0.635" width="0.1524" layer="21"/>
<wire x1="10.16" y1="0.635" x2="10.16" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="10.16" y1="-0.635" x2="9.525" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="8.255" y1="1.27" x2="7.62" y2="0.635" width="0.1524" layer="21"/>
<wire x1="7.62" y1="-0.635" x2="8.255" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="9.525" y1="-1.27" x2="8.255" y2="-1.27" width="0.1524" layer="21"/>
<pad name="1" x="-8.89" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="2" x="-6.35" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="3" x="-3.81" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="4" x="-1.27" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="5" x="1.27" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="6" x="3.81" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="7" x="6.35" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="8" x="8.89" y="0" drill="1.016" shape="long" rot="R90"/>
<text x="-10.2362" y="1.8288" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-10.16" y="-3.175" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="6.096" y1="-0.254" x2="6.604" y2="0.254" layer="51"/>
<rectangle x1="3.556" y1="-0.254" x2="4.064" y2="0.254" layer="51"/>
<rectangle x1="1.016" y1="-0.254" x2="1.524" y2="0.254" layer="51"/>
<rectangle x1="-1.524" y1="-0.254" x2="-1.016" y2="0.254" layer="51"/>
<rectangle x1="-4.064" y1="-0.254" x2="-3.556" y2="0.254" layer="51"/>
<rectangle x1="-6.604" y1="-0.254" x2="-6.096" y2="0.254" layer="51"/>
<rectangle x1="-9.144" y1="-0.254" x2="-8.636" y2="0.254" layer="51"/>
<rectangle x1="8.636" y1="-0.254" x2="9.144" y2="0.254" layer="51"/>
</package>
<package name="1X08/90" urn="urn:adsk.eagle:footprint:22261/1">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-10.16" y1="-1.905" x2="-7.62" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="-1.905" x2="-7.62" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="0.635" x2="-10.16" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="0.635" x2="-10.16" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-8.89" y1="6.985" x2="-8.89" y2="1.27" width="0.762" layer="21"/>
<wire x1="-7.62" y1="-1.905" x2="-5.08" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="-1.905" x2="-5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="0.635" x2="-7.62" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="6.985" x2="-6.35" y2="1.27" width="0.762" layer="21"/>
<wire x1="-5.08" y1="-1.905" x2="-2.54" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="-1.905" x2="-2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="0.635" x2="-5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="6.985" x2="-3.81" y2="1.27" width="0.762" layer="21"/>
<wire x1="-2.54" y1="-1.905" x2="0" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="0" y1="-1.905" x2="0" y2="0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="0.635" x2="-2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="6.985" x2="-1.27" y2="1.27" width="0.762" layer="21"/>
<wire x1="0" y1="-1.905" x2="2.54" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="2.54" y1="-1.905" x2="2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="0.635" x2="0" y2="0.635" width="0.1524" layer="21"/>
<wire x1="1.27" y1="6.985" x2="1.27" y2="1.27" width="0.762" layer="21"/>
<wire x1="2.54" y1="-1.905" x2="5.08" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="5.08" y1="-1.905" x2="5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="5.08" y1="0.635" x2="2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="3.81" y1="6.985" x2="3.81" y2="1.27" width="0.762" layer="21"/>
<wire x1="5.08" y1="-1.905" x2="7.62" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="7.62" y1="-1.905" x2="7.62" y2="0.635" width="0.1524" layer="21"/>
<wire x1="7.62" y1="0.635" x2="5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="6.35" y1="6.985" x2="6.35" y2="1.27" width="0.762" layer="21"/>
<wire x1="7.62" y1="-1.905" x2="10.16" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="10.16" y1="-1.905" x2="10.16" y2="0.635" width="0.1524" layer="21"/>
<wire x1="10.16" y1="0.635" x2="7.62" y2="0.635" width="0.1524" layer="21"/>
<wire x1="8.89" y1="6.985" x2="8.89" y2="1.27" width="0.762" layer="21"/>
<pad name="1" x="-8.89" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="2" x="-6.35" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="3" x="-3.81" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="4" x="-1.27" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="5" x="1.27" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="6" x="3.81" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="7" x="6.35" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="8" x="8.89" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<text x="-10.795" y="-3.81" size="1.27" layer="25" ratio="10" rot="R90">&gt;NAME</text>
<text x="12.065" y="-3.81" size="1.27" layer="27" rot="R90">&gt;VALUE</text>
<rectangle x1="-9.271" y1="0.635" x2="-8.509" y2="1.143" layer="21"/>
<rectangle x1="-6.731" y1="0.635" x2="-5.969" y2="1.143" layer="21"/>
<rectangle x1="-4.191" y1="0.635" x2="-3.429" y2="1.143" layer="21"/>
<rectangle x1="-1.651" y1="0.635" x2="-0.889" y2="1.143" layer="21"/>
<rectangle x1="0.889" y1="0.635" x2="1.651" y2="1.143" layer="21"/>
<rectangle x1="3.429" y1="0.635" x2="4.191" y2="1.143" layer="21"/>
<rectangle x1="5.969" y1="0.635" x2="6.731" y2="1.143" layer="21"/>
<rectangle x1="8.509" y1="0.635" x2="9.271" y2="1.143" layer="21"/>
<rectangle x1="-9.271" y1="-2.921" x2="-8.509" y2="-1.905" layer="21"/>
<rectangle x1="-6.731" y1="-2.921" x2="-5.969" y2="-1.905" layer="21"/>
<rectangle x1="-4.191" y1="-2.921" x2="-3.429" y2="-1.905" layer="21"/>
<rectangle x1="-1.651" y1="-2.921" x2="-0.889" y2="-1.905" layer="21"/>
<rectangle x1="0.889" y1="-2.921" x2="1.651" y2="-1.905" layer="21"/>
<rectangle x1="3.429" y1="-2.921" x2="4.191" y2="-1.905" layer="21"/>
<rectangle x1="5.969" y1="-2.921" x2="6.731" y2="-1.905" layer="21"/>
<rectangle x1="8.509" y1="-2.921" x2="9.271" y2="-1.905" layer="21"/>
</package>
<package name="1X10" urn="urn:adsk.eagle:footprint:22264/1">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="7.62" y1="0.635" x2="8.255" y2="1.27" width="0.1524" layer="21"/>
<wire x1="8.255" y1="1.27" x2="9.525" y2="1.27" width="0.1524" layer="21"/>
<wire x1="9.525" y1="1.27" x2="10.16" y2="0.635" width="0.1524" layer="21"/>
<wire x1="10.16" y1="0.635" x2="10.16" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="10.16" y1="-0.635" x2="9.525" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="9.525" y1="-1.27" x2="8.255" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="8.255" y1="-1.27" x2="7.62" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="3.175" y1="1.27" x2="4.445" y2="1.27" width="0.1524" layer="21"/>
<wire x1="4.445" y1="1.27" x2="5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="5.08" y1="0.635" x2="5.08" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="5.08" y1="-0.635" x2="4.445" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="5.08" y1="0.635" x2="5.715" y2="1.27" width="0.1524" layer="21"/>
<wire x1="5.715" y1="1.27" x2="6.985" y2="1.27" width="0.1524" layer="21"/>
<wire x1="6.985" y1="1.27" x2="7.62" y2="0.635" width="0.1524" layer="21"/>
<wire x1="7.62" y1="0.635" x2="7.62" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="7.62" y1="-0.635" x2="6.985" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="6.985" y1="-1.27" x2="5.715" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="5.715" y1="-1.27" x2="5.08" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="0.635" x2="0.635" y2="1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="1.27" x2="1.905" y2="1.27" width="0.1524" layer="21"/>
<wire x1="1.905" y1="1.27" x2="2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="0.635" x2="2.54" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="-0.635" x2="1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="1.905" y1="-1.27" x2="0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-1.27" x2="0" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="3.175" y1="1.27" x2="2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="-0.635" x2="3.175" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="4.445" y1="-1.27" x2="3.175" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="1.27" x2="-3.175" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="1.27" x2="-2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="0.635" x2="-2.54" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="-0.635" x2="-3.175" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="0.635" x2="-1.905" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="1.27" x2="-0.635" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="1.27" x2="0" y2="0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="0.635" x2="0" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="-0.635" x2="-0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="-1.27" x2="-1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="-1.27" x2="-2.54" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="0.635" x2="-6.985" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-6.985" y1="1.27" x2="-5.715" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-5.715" y1="1.27" x2="-5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="0.635" x2="-5.08" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="-0.635" x2="-5.715" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-5.715" y1="-1.27" x2="-6.985" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-6.985" y1="-1.27" x2="-7.62" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="1.27" x2="-5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="-0.635" x2="-4.445" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="-1.27" x2="-4.445" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-12.065" y1="1.27" x2="-10.795" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-10.795" y1="1.27" x2="-10.16" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="0.635" x2="-10.16" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="-0.635" x2="-10.795" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="0.635" x2="-9.525" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-9.525" y1="1.27" x2="-8.255" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-8.255" y1="1.27" x2="-7.62" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="0.635" x2="-7.62" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="-0.635" x2="-8.255" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-8.255" y1="-1.27" x2="-9.525" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-9.525" y1="-1.27" x2="-10.16" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-12.7" y1="0.635" x2="-12.7" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-12.065" y1="1.27" x2="-12.7" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-12.7" y1="-0.635" x2="-12.065" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-10.795" y1="-1.27" x2="-12.065" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="10.795" y1="1.27" x2="12.065" y2="1.27" width="0.1524" layer="21"/>
<wire x1="12.065" y1="1.27" x2="12.7" y2="0.635" width="0.1524" layer="21"/>
<wire x1="12.7" y1="0.635" x2="12.7" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="12.7" y1="-0.635" x2="12.065" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="10.795" y1="1.27" x2="10.16" y2="0.635" width="0.1524" layer="21"/>
<wire x1="10.16" y1="-0.635" x2="10.795" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="12.065" y1="-1.27" x2="10.795" y2="-1.27" width="0.1524" layer="21"/>
<pad name="1" x="-11.43" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="2" x="-8.89" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="3" x="-6.35" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="4" x="-3.81" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="5" x="-1.27" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="6" x="1.27" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="7" x="3.81" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="8" x="6.35" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="9" x="8.89" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="10" x="11.43" y="0" drill="1.016" shape="long" rot="R90"/>
<text x="-12.7762" y="1.8288" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-12.7" y="-3.175" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="8.636" y1="-0.254" x2="9.144" y2="0.254" layer="51"/>
<rectangle x1="6.096" y1="-0.254" x2="6.604" y2="0.254" layer="51"/>
<rectangle x1="3.556" y1="-0.254" x2="4.064" y2="0.254" layer="51"/>
<rectangle x1="1.016" y1="-0.254" x2="1.524" y2="0.254" layer="51"/>
<rectangle x1="-1.524" y1="-0.254" x2="-1.016" y2="0.254" layer="51"/>
<rectangle x1="-4.064" y1="-0.254" x2="-3.556" y2="0.254" layer="51"/>
<rectangle x1="-6.604" y1="-0.254" x2="-6.096" y2="0.254" layer="51"/>
<rectangle x1="-9.144" y1="-0.254" x2="-8.636" y2="0.254" layer="51"/>
<rectangle x1="-11.684" y1="-0.254" x2="-11.176" y2="0.254" layer="51"/>
<rectangle x1="11.176" y1="-0.254" x2="11.684" y2="0.254" layer="51"/>
</package>
<package name="1X10/90" urn="urn:adsk.eagle:footprint:22265/1">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-12.7" y1="-1.905" x2="-10.16" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="-1.905" x2="-10.16" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="0.635" x2="-12.7" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-12.7" y1="0.635" x2="-12.7" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-11.43" y1="6.985" x2="-11.43" y2="1.27" width="0.762" layer="21"/>
<wire x1="-10.16" y1="-1.905" x2="-7.62" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="-1.905" x2="-7.62" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="0.635" x2="-10.16" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-8.89" y1="6.985" x2="-8.89" y2="1.27" width="0.762" layer="21"/>
<wire x1="-7.62" y1="-1.905" x2="-5.08" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="-1.905" x2="-5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="0.635" x2="-7.62" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="6.985" x2="-6.35" y2="1.27" width="0.762" layer="21"/>
<wire x1="-5.08" y1="-1.905" x2="-2.54" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="-1.905" x2="-2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="0.635" x2="-5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="6.985" x2="-3.81" y2="1.27" width="0.762" layer="21"/>
<wire x1="-2.54" y1="-1.905" x2="0" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="0" y1="-1.905" x2="0" y2="0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="0.635" x2="-2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="6.985" x2="-1.27" y2="1.27" width="0.762" layer="21"/>
<wire x1="0" y1="-1.905" x2="2.54" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="2.54" y1="-1.905" x2="2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="0.635" x2="0" y2="0.635" width="0.1524" layer="21"/>
<wire x1="1.27" y1="6.985" x2="1.27" y2="1.27" width="0.762" layer="21"/>
<wire x1="2.54" y1="-1.905" x2="5.08" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="5.08" y1="-1.905" x2="5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="5.08" y1="0.635" x2="2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="3.81" y1="6.985" x2="3.81" y2="1.27" width="0.762" layer="21"/>
<wire x1="5.08" y1="-1.905" x2="7.62" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="7.62" y1="-1.905" x2="7.62" y2="0.635" width="0.1524" layer="21"/>
<wire x1="7.62" y1="0.635" x2="5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="6.35" y1="6.985" x2="6.35" y2="1.27" width="0.762" layer="21"/>
<wire x1="7.62" y1="-1.905" x2="10.16" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="10.16" y1="-1.905" x2="10.16" y2="0.635" width="0.1524" layer="21"/>
<wire x1="10.16" y1="0.635" x2="7.62" y2="0.635" width="0.1524" layer="21"/>
<wire x1="8.89" y1="6.985" x2="8.89" y2="1.27" width="0.762" layer="21"/>
<wire x1="10.16" y1="-1.905" x2="12.7" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="12.7" y1="-1.905" x2="12.7" y2="0.635" width="0.1524" layer="21"/>
<wire x1="12.7" y1="0.635" x2="10.16" y2="0.635" width="0.1524" layer="21"/>
<wire x1="11.43" y1="6.985" x2="11.43" y2="1.27" width="0.762" layer="21"/>
<pad name="1" x="-11.43" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="2" x="-8.89" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="3" x="-6.35" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="4" x="-3.81" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="5" x="-1.27" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="6" x="1.27" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="7" x="3.81" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="8" x="6.35" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="9" x="8.89" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="10" x="11.43" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<text x="-13.335" y="-3.81" size="1.27" layer="25" ratio="10" rot="R90">&gt;NAME</text>
<text x="14.605" y="-4.445" size="1.27" layer="27" rot="R90">&gt;VALUE</text>
<rectangle x1="-11.811" y1="0.635" x2="-11.049" y2="1.143" layer="21"/>
<rectangle x1="-9.271" y1="0.635" x2="-8.509" y2="1.143" layer="21"/>
<rectangle x1="-6.731" y1="0.635" x2="-5.969" y2="1.143" layer="21"/>
<rectangle x1="-4.191" y1="0.635" x2="-3.429" y2="1.143" layer="21"/>
<rectangle x1="-1.651" y1="0.635" x2="-0.889" y2="1.143" layer="21"/>
<rectangle x1="0.889" y1="0.635" x2="1.651" y2="1.143" layer="21"/>
<rectangle x1="3.429" y1="0.635" x2="4.191" y2="1.143" layer="21"/>
<rectangle x1="5.969" y1="0.635" x2="6.731" y2="1.143" layer="21"/>
<rectangle x1="8.509" y1="0.635" x2="9.271" y2="1.143" layer="21"/>
<rectangle x1="11.049" y1="0.635" x2="11.811" y2="1.143" layer="21"/>
<rectangle x1="-11.811" y1="-2.921" x2="-11.049" y2="-1.905" layer="21"/>
<rectangle x1="-9.271" y1="-2.921" x2="-8.509" y2="-1.905" layer="21"/>
<rectangle x1="-6.731" y1="-2.921" x2="-5.969" y2="-1.905" layer="21"/>
<rectangle x1="-4.191" y1="-2.921" x2="-3.429" y2="-1.905" layer="21"/>
<rectangle x1="-1.651" y1="-2.921" x2="-0.889" y2="-1.905" layer="21"/>
<rectangle x1="0.889" y1="-2.921" x2="1.651" y2="-1.905" layer="21"/>
<rectangle x1="3.429" y1="-2.921" x2="4.191" y2="-1.905" layer="21"/>
<rectangle x1="5.969" y1="-2.921" x2="6.731" y2="-1.905" layer="21"/>
<rectangle x1="8.509" y1="-2.921" x2="9.271" y2="-1.905" layer="21"/>
<rectangle x1="11.049" y1="-2.921" x2="11.811" y2="-1.905" layer="21"/>
</package>
<package name="1X07" urn="urn:adsk.eagle:footprint:22367/1">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="3.81" y1="0.635" x2="4.445" y2="1.27" width="0.1524" layer="21"/>
<wire x1="4.445" y1="1.27" x2="5.715" y2="1.27" width="0.1524" layer="21"/>
<wire x1="5.715" y1="1.27" x2="6.35" y2="0.635" width="0.1524" layer="21"/>
<wire x1="6.35" y1="0.635" x2="6.35" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="6.35" y1="-0.635" x2="5.715" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="5.715" y1="-1.27" x2="4.445" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="4.445" y1="-1.27" x2="3.81" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="1.27" x2="0.635" y2="1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="1.27" x2="1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="1.27" y1="0.635" x2="1.27" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="1.27" y1="-0.635" x2="0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="1.27" y1="0.635" x2="1.905" y2="1.27" width="0.1524" layer="21"/>
<wire x1="1.905" y1="1.27" x2="3.175" y2="1.27" width="0.1524" layer="21"/>
<wire x1="3.175" y1="1.27" x2="3.81" y2="0.635" width="0.1524" layer="21"/>
<wire x1="3.81" y1="0.635" x2="3.81" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="3.81" y1="-0.635" x2="3.175" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="3.175" y1="-1.27" x2="1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="1.905" y1="-1.27" x2="1.27" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="0.635" x2="-3.175" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="1.27" x2="-1.905" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="1.27" x2="-1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="0.635" x2="-1.27" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="-0.635" x2="-1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="-1.27" x2="-3.175" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="-1.27" x2="-3.81" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="1.27" x2="-1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="-0.635" x2="-0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-1.27" x2="-0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-8.255" y1="1.27" x2="-6.985" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-6.985" y1="1.27" x2="-6.35" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="0.635" x2="-6.35" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="-0.635" x2="-6.985" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="0.635" x2="-5.715" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-5.715" y1="1.27" x2="-4.445" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="1.27" x2="-3.81" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="0.635" x2="-3.81" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="-0.635" x2="-4.445" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="-1.27" x2="-5.715" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-5.715" y1="-1.27" x2="-6.35" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-8.89" y1="0.635" x2="-8.89" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-8.255" y1="1.27" x2="-8.89" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-8.89" y1="-0.635" x2="-8.255" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-6.985" y1="-1.27" x2="-8.255" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="6.985" y1="1.27" x2="8.255" y2="1.27" width="0.1524" layer="21"/>
<wire x1="8.255" y1="1.27" x2="8.89" y2="0.635" width="0.1524" layer="21"/>
<wire x1="8.89" y1="0.635" x2="8.89" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="8.89" y1="-0.635" x2="8.255" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="6.985" y1="1.27" x2="6.35" y2="0.635" width="0.1524" layer="21"/>
<wire x1="6.35" y1="-0.635" x2="6.985" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="8.255" y1="-1.27" x2="6.985" y2="-1.27" width="0.1524" layer="21"/>
<pad name="1" x="-7.62" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="2" x="-5.08" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="3" x="-2.54" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="4" x="0" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="5" x="2.54" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="6" x="5.08" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="7" x="7.62" y="0" drill="1.016" shape="long" rot="R90"/>
<text x="-8.9662" y="1.8288" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-8.89" y="-3.175" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="4.826" y1="-0.254" x2="5.334" y2="0.254" layer="51"/>
<rectangle x1="2.286" y1="-0.254" x2="2.794" y2="0.254" layer="51"/>
<rectangle x1="-0.254" y1="-0.254" x2="0.254" y2="0.254" layer="51"/>
<rectangle x1="-2.794" y1="-0.254" x2="-2.286" y2="0.254" layer="51"/>
<rectangle x1="-5.334" y1="-0.254" x2="-4.826" y2="0.254" layer="51"/>
<rectangle x1="-7.874" y1="-0.254" x2="-7.366" y2="0.254" layer="51"/>
<rectangle x1="7.366" y1="-0.254" x2="7.874" y2="0.254" layer="51"/>
</package>
<package name="1X07/90" urn="urn:adsk.eagle:footprint:22368/1">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-8.89" y1="-1.905" x2="-6.35" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="-1.905" x2="-6.35" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="0.635" x2="-8.89" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-8.89" y1="0.635" x2="-8.89" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="6.985" x2="-7.62" y2="1.27" width="0.762" layer="21"/>
<wire x1="-6.35" y1="-1.905" x2="-3.81" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="-1.905" x2="-3.81" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="0.635" x2="-6.35" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="6.985" x2="-5.08" y2="1.27" width="0.762" layer="21"/>
<wire x1="-3.81" y1="-1.905" x2="-1.27" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="-1.905" x2="-1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="0.635" x2="-3.81" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="6.985" x2="-2.54" y2="1.27" width="0.762" layer="21"/>
<wire x1="-1.27" y1="-1.905" x2="1.27" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="1.27" y1="-1.905" x2="1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="1.27" y1="0.635" x2="-1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="6.985" x2="0" y2="1.27" width="0.762" layer="21"/>
<wire x1="1.27" y1="-1.905" x2="3.81" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="3.81" y1="-1.905" x2="3.81" y2="0.635" width="0.1524" layer="21"/>
<wire x1="3.81" y1="0.635" x2="1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="6.985" x2="2.54" y2="1.27" width="0.762" layer="21"/>
<wire x1="3.81" y1="-1.905" x2="6.35" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="6.35" y1="-1.905" x2="6.35" y2="0.635" width="0.1524" layer="21"/>
<wire x1="6.35" y1="0.635" x2="3.81" y2="0.635" width="0.1524" layer="21"/>
<wire x1="5.08" y1="6.985" x2="5.08" y2="1.27" width="0.762" layer="21"/>
<wire x1="6.35" y1="-1.905" x2="8.89" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="8.89" y1="-1.905" x2="8.89" y2="0.635" width="0.1524" layer="21"/>
<wire x1="8.89" y1="0.635" x2="6.35" y2="0.635" width="0.1524" layer="21"/>
<wire x1="7.62" y1="6.985" x2="7.62" y2="1.27" width="0.762" layer="21"/>
<pad name="1" x="-7.62" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="2" x="-5.08" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="3" x="-2.54" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="4" x="0" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="5" x="2.54" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="6" x="5.08" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="7" x="7.62" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<text x="-9.525" y="-3.81" size="1.27" layer="25" ratio="10" rot="R90">&gt;NAME</text>
<text x="10.795" y="-3.81" size="1.27" layer="27" rot="R90">&gt;VALUE</text>
<rectangle x1="-8.001" y1="0.635" x2="-7.239" y2="1.143" layer="21"/>
<rectangle x1="-5.461" y1="0.635" x2="-4.699" y2="1.143" layer="21"/>
<rectangle x1="-2.921" y1="0.635" x2="-2.159" y2="1.143" layer="21"/>
<rectangle x1="-0.381" y1="0.635" x2="0.381" y2="1.143" layer="21"/>
<rectangle x1="2.159" y1="0.635" x2="2.921" y2="1.143" layer="21"/>
<rectangle x1="4.699" y1="0.635" x2="5.461" y2="1.143" layer="21"/>
<rectangle x1="7.239" y1="0.635" x2="8.001" y2="1.143" layer="21"/>
<rectangle x1="-8.001" y1="-2.921" x2="-7.239" y2="-1.905" layer="21"/>
<rectangle x1="-5.461" y1="-2.921" x2="-4.699" y2="-1.905" layer="21"/>
<rectangle x1="-2.921" y1="-2.921" x2="-2.159" y2="-1.905" layer="21"/>
<rectangle x1="-0.381" y1="-2.921" x2="0.381" y2="-1.905" layer="21"/>
<rectangle x1="2.159" y1="-2.921" x2="2.921" y2="-1.905" layer="21"/>
<rectangle x1="4.699" y1="-2.921" x2="5.461" y2="-1.905" layer="21"/>
<rectangle x1="7.239" y1="-2.921" x2="8.001" y2="-1.905" layer="21"/>
</package>
</packages>
<packages3d>
<package3d name="1X08" urn="urn:adsk.eagle:package:22409/2" type="model">
<description>PIN HEADER</description>
<packageinstances>
<packageinstance name="1X08"/>
</packageinstances>
</package3d>
<package3d name="1X08/90" urn="urn:adsk.eagle:package:22413/2" type="model">
<description>PIN HEADER</description>
<packageinstances>
<packageinstance name="1X08/90"/>
</packageinstances>
</package3d>
<package3d name="1X10" urn="urn:adsk.eagle:package:22406/2" type="model">
<description>PIN HEADER</description>
<packageinstances>
<packageinstance name="1X10"/>
</packageinstances>
</package3d>
<package3d name="1X10/90" urn="urn:adsk.eagle:package:22408/2" type="model">
<description>PIN HEADER</description>
<packageinstances>
<packageinstance name="1X10/90"/>
</packageinstances>
</package3d>
<package3d name="1X07" urn="urn:adsk.eagle:package:22477/2" type="model">
<description>PIN HEADER</description>
<packageinstances>
<packageinstance name="1X07"/>
</packageinstances>
</package3d>
<package3d name="1X07/90" urn="urn:adsk.eagle:package:22476/2" type="model">
<description>PIN HEADER</description>
<packageinstances>
<packageinstance name="1X07/90"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="PINHD8" urn="urn:adsk.eagle:symbol:22260/1">
<wire x1="-6.35" y1="-10.16" x2="1.27" y2="-10.16" width="0.4064" layer="94"/>
<wire x1="1.27" y1="-10.16" x2="1.27" y2="12.7" width="0.4064" layer="94"/>
<wire x1="1.27" y1="12.7" x2="-6.35" y2="12.7" width="0.4064" layer="94"/>
<wire x1="-6.35" y1="12.7" x2="-6.35" y2="-10.16" width="0.4064" layer="94"/>
<text x="-6.35" y="13.335" size="1.778" layer="95">&gt;NAME</text>
<text x="-6.35" y="-12.7" size="1.778" layer="96">&gt;VALUE</text>
<pin name="1" x="-2.54" y="10.16" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="2" x="-2.54" y="7.62" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="3" x="-2.54" y="5.08" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="4" x="-2.54" y="2.54" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="5" x="-2.54" y="0" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="6" x="-2.54" y="-2.54" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="7" x="-2.54" y="-5.08" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="8" x="-2.54" y="-7.62" visible="pad" length="short" direction="pas" function="dot"/>
</symbol>
<symbol name="PINHD10" urn="urn:adsk.eagle:symbol:22263/1">
<wire x1="-6.35" y1="-15.24" x2="1.27" y2="-15.24" width="0.4064" layer="94"/>
<wire x1="1.27" y1="-15.24" x2="1.27" y2="12.7" width="0.4064" layer="94"/>
<wire x1="1.27" y1="12.7" x2="-6.35" y2="12.7" width="0.4064" layer="94"/>
<wire x1="-6.35" y1="12.7" x2="-6.35" y2="-15.24" width="0.4064" layer="94"/>
<text x="-6.35" y="13.335" size="1.778" layer="95">&gt;NAME</text>
<text x="-6.35" y="-17.78" size="1.778" layer="96">&gt;VALUE</text>
<pin name="1" x="-2.54" y="10.16" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="2" x="-2.54" y="7.62" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="3" x="-2.54" y="5.08" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="4" x="-2.54" y="2.54" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="5" x="-2.54" y="0" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="6" x="-2.54" y="-2.54" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="7" x="-2.54" y="-5.08" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="8" x="-2.54" y="-7.62" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="9" x="-2.54" y="-10.16" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="10" x="-2.54" y="-12.7" visible="pad" length="short" direction="pas" function="dot"/>
</symbol>
<symbol name="PINHD7" urn="urn:adsk.eagle:symbol:22366/1">
<wire x1="-6.35" y1="-10.16" x2="1.27" y2="-10.16" width="0.4064" layer="94"/>
<wire x1="1.27" y1="-10.16" x2="1.27" y2="10.16" width="0.4064" layer="94"/>
<wire x1="1.27" y1="10.16" x2="-6.35" y2="10.16" width="0.4064" layer="94"/>
<wire x1="-6.35" y1="10.16" x2="-6.35" y2="-10.16" width="0.4064" layer="94"/>
<text x="-6.35" y="10.795" size="1.778" layer="95">&gt;NAME</text>
<text x="-6.35" y="-12.7" size="1.778" layer="96">&gt;VALUE</text>
<pin name="1" x="-2.54" y="7.62" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="2" x="-2.54" y="5.08" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="3" x="-2.54" y="2.54" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="4" x="-2.54" y="0" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="5" x="-2.54" y="-2.54" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="6" x="-2.54" y="-5.08" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="7" x="-2.54" y="-7.62" visible="pad" length="short" direction="pas" function="dot"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="PINHD-1X8" urn="urn:adsk.eagle:component:16494884/4" prefix="JP">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<gates>
<gate name="A" symbol="PINHD8" x="0" y="0"/>
</gates>
<devices>
<device name="" package="1X08">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="2" pad="2"/>
<connect gate="A" pin="3" pad="3"/>
<connect gate="A" pin="4" pad="4"/>
<connect gate="A" pin="5" pad="5"/>
<connect gate="A" pin="6" pad="6"/>
<connect gate="A" pin="7" pad="7"/>
<connect gate="A" pin="8" pad="8"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:22409/2"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="CATEGORY" value="Headers" constant="no"/>
<attribute name="DESCRIPTION" value="Header, Straight, 8 Position" constant="no"/>
<attribute name="MANUFACTURER" value="Generic" constant="no"/>
<attribute name="MPN" value="Generic" constant="no"/>
<attribute name="OPERATING_TEMPERATURE" value="Generic" constant="no"/>
<attribute name="PART_STATUS" value="Active" constant="no"/>
<attribute name="PITCH" value="0.100&quot; (2.54mm)" constant="no"/>
<attribute name="ROHS_COMPLIANCE" value="Generic" constant="no"/>
<attribute name="SERIES" value="Generic" constant="no"/>
<attribute name="SUB-CATEGORY" value="Headers, Male Pins" constant="no"/>
<attribute name="TYPE" value="Board to Board or Cable, Unshrouded, Through Hole, Straight" constant="no"/>
</technology>
</technologies>
</device>
<device name="/90" package="1X08/90">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="2" pad="2"/>
<connect gate="A" pin="3" pad="3"/>
<connect gate="A" pin="4" pad="4"/>
<connect gate="A" pin="5" pad="5"/>
<connect gate="A" pin="6" pad="6"/>
<connect gate="A" pin="7" pad="7"/>
<connect gate="A" pin="8" pad="8"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:22413/2"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="CATEGORY" value="Headers" constant="no"/>
<attribute name="DESCRIPTION" value="Header, Right Angle, 8 Position" constant="no"/>
<attribute name="MANUFACTURER" value="Generic" constant="no"/>
<attribute name="MPN" value="Generic" constant="no"/>
<attribute name="OPERATING_TEMPERATURE" value="Generic" constant="no"/>
<attribute name="PART_STATUS" value="Active" constant="no"/>
<attribute name="PITCH" value="0.100&quot; (2.54mm)" constant="no"/>
<attribute name="ROHS_COMPLIANCE" value="Generic" constant="no"/>
<attribute name="SERIES" value="Generic" constant="no"/>
<attribute name="SUB-CATEGORY" value="Headers, Male Pins" constant="no"/>
<attribute name="TYPE" value="Board to Board or Cable, Unshrouded, Through Hole, Right Angle" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="PINHD-1X10" urn="urn:adsk.eagle:component:16494880/4" prefix="JP">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<gates>
<gate name="A" symbol="PINHD10" x="0" y="0"/>
</gates>
<devices>
<device name="" package="1X10">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="10" pad="10"/>
<connect gate="A" pin="2" pad="2"/>
<connect gate="A" pin="3" pad="3"/>
<connect gate="A" pin="4" pad="4"/>
<connect gate="A" pin="5" pad="5"/>
<connect gate="A" pin="6" pad="6"/>
<connect gate="A" pin="7" pad="7"/>
<connect gate="A" pin="8" pad="8"/>
<connect gate="A" pin="9" pad="9"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:22406/2"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="CATEGORY" value="Headers" constant="no"/>
<attribute name="DESCRIPTION" value="Header, Straight, 10 Position " constant="no"/>
<attribute name="MANUFACTURER" value="Generic" constant="no"/>
<attribute name="MPN" value="Generic" constant="no"/>
<attribute name="OPERATING_TEMPERATURE" value="Generic" constant="no"/>
<attribute name="PART_STATUS" value="Active" constant="no"/>
<attribute name="PITCH" value="0.100&quot; (2.54mm)" constant="no"/>
<attribute name="ROHS_COMPLIANCE" value="Generic" constant="no"/>
<attribute name="SERIES" value="Generic" constant="no"/>
<attribute name="SUB-CATEGORY" value="Headers, Male Pins" constant="no"/>
<attribute name="TYPE" value="Board to Board or Cable, Unshrouded, Through Hole, Straight" constant="no"/>
</technology>
</technologies>
</device>
<device name="/90" package="1X10/90">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="10" pad="10"/>
<connect gate="A" pin="2" pad="2"/>
<connect gate="A" pin="3" pad="3"/>
<connect gate="A" pin="4" pad="4"/>
<connect gate="A" pin="5" pad="5"/>
<connect gate="A" pin="6" pad="6"/>
<connect gate="A" pin="7" pad="7"/>
<connect gate="A" pin="8" pad="8"/>
<connect gate="A" pin="9" pad="9"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:22408/2"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="CATEGORY" value="Headers" constant="no"/>
<attribute name="DESCRIPTION" value="Header, Right  Angle, 10 Position " constant="no"/>
<attribute name="MANUFACTURER" value="Generic" constant="no"/>
<attribute name="MPN" value="Generic" constant="no"/>
<attribute name="OPERATING_TEMPERATURE" value="Generic" constant="no"/>
<attribute name="PART_STATUS" value="Active" constant="no"/>
<attribute name="PITCH" value="0.100&quot; (2.54mm)" constant="no"/>
<attribute name="ROHS_COMPLIANCE" value="Generic" constant="no"/>
<attribute name="SERIES" value="Generic" constant="no"/>
<attribute name="SUB-CATEGORY" value="Headers, Male Pins" constant="no"/>
<attribute name="TYPE" value="Board to Board or Cable, Unshrouded, Through Hole, Right Angle" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="PINHD-1X7" urn="urn:adsk.eagle:component:16494883/4" prefix="JP">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<gates>
<gate name="A" symbol="PINHD7" x="0" y="0"/>
</gates>
<devices>
<device name="" package="1X07">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="2" pad="2"/>
<connect gate="A" pin="3" pad="3"/>
<connect gate="A" pin="4" pad="4"/>
<connect gate="A" pin="5" pad="5"/>
<connect gate="A" pin="6" pad="6"/>
<connect gate="A" pin="7" pad="7"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:22477/2"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="CATEGORY" value="Headers" constant="no"/>
<attribute name="DESCRIPTION" value="Header, Straight, 7 Position" constant="no"/>
<attribute name="MANUFACTURER" value="Generic" constant="no"/>
<attribute name="MPN" value="Generic" constant="no"/>
<attribute name="OPERATING_TEMPERATURE" value="Generic" constant="no"/>
<attribute name="PART_STATUS" value="Active" constant="no"/>
<attribute name="PITCH" value="0.100&quot; (2.54mm)" constant="no"/>
<attribute name="ROHS_COMPLIANCE" value="Generic" constant="no"/>
<attribute name="SERIES" value="Generic" constant="no"/>
<attribute name="SUB-CATEGORY" value="Headers, Male Pins" constant="no"/>
<attribute name="TYPE" value="Board to Board or Cable, Unshrouded, Through Hole, Straight" constant="no"/>
</technology>
</technologies>
</device>
<device name="/90" package="1X07/90">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="2" pad="2"/>
<connect gate="A" pin="3" pad="3"/>
<connect gate="A" pin="4" pad="4"/>
<connect gate="A" pin="5" pad="5"/>
<connect gate="A" pin="6" pad="6"/>
<connect gate="A" pin="7" pad="7"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:22476/2"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="CATEGORY" value="Headers" constant="no"/>
<attribute name="DESCRIPTION" value="Header, Right Angle, 7 Position" constant="no"/>
<attribute name="MANUFACTURER" value="Generic" constant="no"/>
<attribute name="MPN" value="Generic" constant="no"/>
<attribute name="OPERATING_TEMPERATURE" value="Generic" constant="no"/>
<attribute name="PART_STATUS" value="Active" constant="no"/>
<attribute name="PITCH" value="0.100&quot; (2.54mm)" constant="no"/>
<attribute name="ROHS_COMPLIANCE" value="Generic" constant="no"/>
<attribute name="SERIES" value="Generic" constant="no"/>
<attribute name="SUB-CATEGORY" value="Headers, Male Pins" constant="no"/>
<attribute name="TYPE" value="Board to Board or Cable, Unshrouded, Through Hole, Right Angle" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="ADG732BSUZ-REEL">
<description>&lt;16-/32-Channel, 4 , +1.8 V to +5.5 V and +/-2.5 V Analog Multiplexers.&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by SamacSys&lt;/author&gt;</description>
<packages>
<package name="QFP50P900X900X120-48N">
<description>&lt;b&gt;SU-48 (TQFP)&lt;/b&gt;&lt;br&gt;
</description>
<smd name="1" x="-4.238" y="2.75" dx="1.475" dy="0.3" layer="1"/>
<smd name="2" x="-4.238" y="2.25" dx="1.475" dy="0.3" layer="1"/>
<smd name="3" x="-4.238" y="1.75" dx="1.475" dy="0.3" layer="1"/>
<smd name="4" x="-4.238" y="1.25" dx="1.475" dy="0.3" layer="1"/>
<smd name="5" x="-4.238" y="0.75" dx="1.475" dy="0.3" layer="1"/>
<smd name="6" x="-4.238" y="0.25" dx="1.475" dy="0.3" layer="1"/>
<smd name="7" x="-4.238" y="-0.25" dx="1.475" dy="0.3" layer="1"/>
<smd name="8" x="-4.238" y="-0.75" dx="1.475" dy="0.3" layer="1"/>
<smd name="9" x="-4.238" y="-1.25" dx="1.475" dy="0.3" layer="1"/>
<smd name="10" x="-4.238" y="-1.75" dx="1.475" dy="0.3" layer="1"/>
<smd name="11" x="-4.238" y="-2.25" dx="1.475" dy="0.3" layer="1"/>
<smd name="12" x="-4.238" y="-2.75" dx="1.475" dy="0.3" layer="1"/>
<smd name="13" x="-2.75" y="-4.238" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="14" x="-2.25" y="-4.238" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="15" x="-1.75" y="-4.238" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="16" x="-1.25" y="-4.238" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="17" x="-0.75" y="-4.238" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="18" x="-0.25" y="-4.238" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="19" x="0.25" y="-4.238" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="20" x="0.75" y="-4.238" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="21" x="1.25" y="-4.238" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="22" x="1.75" y="-4.238" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="23" x="2.25" y="-4.238" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="24" x="2.75" y="-4.238" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="25" x="4.238" y="-2.75" dx="1.475" dy="0.3" layer="1"/>
<smd name="26" x="4.238" y="-2.25" dx="1.475" dy="0.3" layer="1"/>
<smd name="27" x="4.238" y="-1.75" dx="1.475" dy="0.3" layer="1"/>
<smd name="28" x="4.238" y="-1.25" dx="1.475" dy="0.3" layer="1"/>
<smd name="29" x="4.238" y="-0.75" dx="1.475" dy="0.3" layer="1"/>
<smd name="30" x="4.238" y="-0.25" dx="1.475" dy="0.3" layer="1"/>
<smd name="31" x="4.238" y="0.25" dx="1.475" dy="0.3" layer="1"/>
<smd name="32" x="4.238" y="0.75" dx="1.475" dy="0.3" layer="1"/>
<smd name="33" x="4.238" y="1.25" dx="1.475" dy="0.3" layer="1"/>
<smd name="34" x="4.238" y="1.75" dx="1.475" dy="0.3" layer="1"/>
<smd name="35" x="4.238" y="2.25" dx="1.475" dy="0.3" layer="1"/>
<smd name="36" x="4.238" y="2.75" dx="1.475" dy="0.3" layer="1"/>
<smd name="37" x="2.75" y="4.238" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="38" x="2.25" y="4.238" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="39" x="1.75" y="4.238" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="40" x="1.25" y="4.238" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="41" x="0.75" y="4.238" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="42" x="0.25" y="4.238" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="43" x="-0.25" y="4.238" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="44" x="-0.75" y="4.238" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="45" x="-1.25" y="4.238" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="46" x="-1.75" y="4.238" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="47" x="-2.25" y="4.238" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="48" x="-2.75" y="4.238" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<text x="0" y="0" size="1.27" layer="25" align="center">&gt;NAME</text>
<text x="0" y="0" size="1.27" layer="27" align="center">&gt;VALUE</text>
<wire x1="-5.225" y1="5.225" x2="5.225" y2="5.225" width="0.05" layer="51"/>
<wire x1="5.225" y1="5.225" x2="5.225" y2="-5.225" width="0.05" layer="51"/>
<wire x1="5.225" y1="-5.225" x2="-5.225" y2="-5.225" width="0.05" layer="51"/>
<wire x1="-5.225" y1="-5.225" x2="-5.225" y2="5.225" width="0.05" layer="51"/>
<wire x1="-3.5" y1="3.5" x2="3.5" y2="3.5" width="0.1" layer="51"/>
<wire x1="3.5" y1="3.5" x2="3.5" y2="-3.5" width="0.1" layer="51"/>
<wire x1="3.5" y1="-3.5" x2="-3.5" y2="-3.5" width="0.1" layer="51"/>
<wire x1="-3.5" y1="-3.5" x2="-3.5" y2="3.5" width="0.1" layer="51"/>
<wire x1="-3.5" y1="3" x2="-3" y2="3.5" width="0.1" layer="51"/>
<wire x1="-3.15" y1="3.15" x2="3.15" y2="3.15" width="0.2" layer="21"/>
<wire x1="3.15" y1="3.15" x2="3.15" y2="-3.15" width="0.2" layer="21"/>
<wire x1="3.15" y1="-3.15" x2="-3.15" y2="-3.15" width="0.2" layer="21"/>
<wire x1="-3.15" y1="-3.15" x2="-3.15" y2="3.15" width="0.2" layer="21"/>
<circle x="-4.725" y="3.5" radius="0.125" width="0.25" layer="25"/>
</package>
</packages>
<symbols>
<symbol name="ADG732BSUZ-REEL">
<wire x1="5.08" y1="12.7" x2="38.1" y2="12.7" width="0.254" layer="94"/>
<wire x1="38.1" y1="-40.64" x2="38.1" y2="12.7" width="0.254" layer="94"/>
<wire x1="38.1" y1="-40.64" x2="5.08" y2="-40.64" width="0.254" layer="94"/>
<wire x1="5.08" y1="12.7" x2="5.08" y2="-40.64" width="0.254" layer="94"/>
<text x="39.37" y="17.78" size="1.778" layer="95" align="center-left">&gt;NAME</text>
<text x="39.37" y="15.24" size="1.778" layer="96" align="center-left">&gt;VALUE</text>
<pin name="S12" x="0" y="0" length="middle"/>
<pin name="S11" x="0" y="-2.54" length="middle"/>
<pin name="S10" x="0" y="-5.08" length="middle"/>
<pin name="S9" x="0" y="-7.62" length="middle"/>
<pin name="S8" x="0" y="-10.16" length="middle"/>
<pin name="S7" x="0" y="-12.7" length="middle"/>
<pin name="S6" x="0" y="-15.24" length="middle"/>
<pin name="S5" x="0" y="-17.78" length="middle"/>
<pin name="S4" x="0" y="-20.32" length="middle"/>
<pin name="S3" x="0" y="-22.86" length="middle"/>
<pin name="S2" x="0" y="-25.4" length="middle"/>
<pin name="S1" x="0" y="-27.94" length="middle"/>
<pin name="VDD_1" x="7.62" y="-45.72" length="middle" rot="R90"/>
<pin name="VDD_2" x="10.16" y="-45.72" length="middle" rot="R90"/>
<pin name="A0" x="12.7" y="-45.72" length="middle" rot="R90"/>
<pin name="A1" x="15.24" y="-45.72" length="middle" rot="R90"/>
<pin name="A2" x="17.78" y="-45.72" length="middle" rot="R90"/>
<pin name="A3" x="20.32" y="-45.72" length="middle" rot="R90"/>
<pin name="A4" x="22.86" y="-45.72" length="middle" rot="R90"/>
<pin name="!CS" x="25.4" y="-45.72" length="middle" rot="R90"/>
<pin name="!WR" x="27.94" y="-45.72" length="middle" rot="R90"/>
<pin name="!EN" x="30.48" y="-45.72" length="middle" rot="R90"/>
<pin name="GND" x="33.02" y="-45.72" length="middle" rot="R90"/>
<pin name="VSS" x="35.56" y="-45.72" length="middle" rot="R90"/>
<pin name="S28" x="43.18" y="0" length="middle" rot="R180"/>
<pin name="S27" x="43.18" y="-2.54" length="middle" rot="R180"/>
<pin name="S26" x="43.18" y="-5.08" length="middle" rot="R180"/>
<pin name="S25" x="43.18" y="-7.62" length="middle" rot="R180"/>
<pin name="S24" x="43.18" y="-10.16" length="middle" rot="R180"/>
<pin name="S23" x="43.18" y="-12.7" length="middle" rot="R180"/>
<pin name="S22" x="43.18" y="-15.24" length="middle" rot="R180"/>
<pin name="S21" x="43.18" y="-17.78" length="middle" rot="R180"/>
<pin name="S20" x="43.18" y="-20.32" length="middle" rot="R180"/>
<pin name="S19" x="43.18" y="-22.86" length="middle" rot="R180"/>
<pin name="S18" x="43.18" y="-25.4" length="middle" rot="R180"/>
<pin name="S17" x="43.18" y="-27.94" length="middle" rot="R180"/>
<pin name="S13" x="7.62" y="17.78" length="middle" rot="R270"/>
<pin name="S14" x="10.16" y="17.78" length="middle" rot="R270"/>
<pin name="S15" x="12.7" y="17.78" length="middle" rot="R270"/>
<pin name="S16" x="15.24" y="17.78" length="middle" rot="R270"/>
<pin name="NIC_3" x="17.78" y="17.78" length="middle" rot="R270"/>
<pin name="D" x="20.32" y="17.78" length="middle" rot="R270"/>
<pin name="NIC_2" x="22.86" y="17.78" length="middle" rot="R270"/>
<pin name="NIC_1" x="25.4" y="17.78" length="middle" rot="R270"/>
<pin name="S32" x="27.94" y="17.78" length="middle" rot="R270"/>
<pin name="S31" x="30.48" y="17.78" length="middle" rot="R270"/>
<pin name="S30" x="33.02" y="17.78" length="middle" rot="R270"/>
<pin name="S29" x="35.56" y="17.78" length="middle" rot="R270"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="ADG732BSUZ-REEL" prefix="IC">
<description>&lt;b&gt;16-/32-Channel, 4 , +1.8 V to +5.5 V and +/-2.5 V Analog Multiplexers.&lt;/b&gt;&lt;p&gt;
Source: &lt;a href="https://componentsearchengine.com/Datasheets/1/ADG732BSUZ-REEL.pdf"&gt; Datasheet &lt;/a&gt;</description>
<gates>
<gate name="G$1" symbol="ADG732BSUZ-REEL" x="0" y="0"/>
</gates>
<devices>
<device name="" package="QFP50P900X900X120-48N">
<connects>
<connect gate="G$1" pin="!CS" pad="20"/>
<connect gate="G$1" pin="!EN" pad="22"/>
<connect gate="G$1" pin="!WR" pad="21"/>
<connect gate="G$1" pin="A0" pad="15"/>
<connect gate="G$1" pin="A1" pad="16"/>
<connect gate="G$1" pin="A2" pad="17"/>
<connect gate="G$1" pin="A3" pad="18"/>
<connect gate="G$1" pin="A4" pad="19"/>
<connect gate="G$1" pin="D" pad="43"/>
<connect gate="G$1" pin="GND" pad="23"/>
<connect gate="G$1" pin="NIC_1" pad="41"/>
<connect gate="G$1" pin="NIC_2" pad="42"/>
<connect gate="G$1" pin="NIC_3" pad="44"/>
<connect gate="G$1" pin="S1" pad="12"/>
<connect gate="G$1" pin="S10" pad="3"/>
<connect gate="G$1" pin="S11" pad="2"/>
<connect gate="G$1" pin="S12" pad="1"/>
<connect gate="G$1" pin="S13" pad="48"/>
<connect gate="G$1" pin="S14" pad="47"/>
<connect gate="G$1" pin="S15" pad="46"/>
<connect gate="G$1" pin="S16" pad="45"/>
<connect gate="G$1" pin="S17" pad="25"/>
<connect gate="G$1" pin="S18" pad="26"/>
<connect gate="G$1" pin="S19" pad="27"/>
<connect gate="G$1" pin="S2" pad="11"/>
<connect gate="G$1" pin="S20" pad="28"/>
<connect gate="G$1" pin="S21" pad="29"/>
<connect gate="G$1" pin="S22" pad="30"/>
<connect gate="G$1" pin="S23" pad="31"/>
<connect gate="G$1" pin="S24" pad="32"/>
<connect gate="G$1" pin="S25" pad="33"/>
<connect gate="G$1" pin="S26" pad="34"/>
<connect gate="G$1" pin="S27" pad="35"/>
<connect gate="G$1" pin="S28" pad="36"/>
<connect gate="G$1" pin="S29" pad="37"/>
<connect gate="G$1" pin="S3" pad="10"/>
<connect gate="G$1" pin="S30" pad="38"/>
<connect gate="G$1" pin="S31" pad="39"/>
<connect gate="G$1" pin="S32" pad="40"/>
<connect gate="G$1" pin="S4" pad="9"/>
<connect gate="G$1" pin="S5" pad="8"/>
<connect gate="G$1" pin="S6" pad="7"/>
<connect gate="G$1" pin="S7" pad="6"/>
<connect gate="G$1" pin="S8" pad="5"/>
<connect gate="G$1" pin="S9" pad="4"/>
<connect gate="G$1" pin="VDD_1" pad="13"/>
<connect gate="G$1" pin="VDD_2" pad="14"/>
<connect gate="G$1" pin="VSS" pad="24"/>
</connects>
<technologies>
<technology name="">
<attribute name="DESCRIPTION" value="16-/32-Channel, 4 , +1.8 V to +5.5 V and +/-2.5 V Analog Multiplexers." constant="no"/>
<attribute name="HEIGHT" value="1.2mm" constant="no"/>
<attribute name="MANUFACTURER_NAME" value="Analog Devices" constant="no"/>
<attribute name="MANUFACTURER_PART_NUMBER" value="ADG732BSUZ-REEL" constant="no"/>
<attribute name="MOUSER_PART_NUMBER" value="584-ADG732BSUZ-R" constant="no"/>
<attribute name="MOUSER_PRICE-STOCK" value="https://www.mouser.co.uk/ProductDetail/Analog-Devices/ADG732BSUZ-REEL?qs=BpaRKvA4VqGYLEdHjoL3%2FQ%3D%3D" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<groups>
<schematic_group name="BREAKOUT"/>
<schematic_group name="IC"/>
</groups>
<parts>
<part name="JP1" library="Connector" deviceset="PINHD-1X8" device="" package3d_urn="urn:adsk.eagle:package:22409/2"/>
<part name="JP2" library="Connector" deviceset="PINHD-1X8" device="" package3d_urn="urn:adsk.eagle:package:22409/2"/>
<part name="JP4" library="Connector" deviceset="PINHD-1X10" device="" package3d_urn="urn:adsk.eagle:package:22406/2"/>
<part name="JP3" library="Connector" deviceset="PINHD-1X8" device="" package3d_urn="urn:adsk.eagle:package:22409/2"/>
<part name="JP5" library="Connector" deviceset="PINHD-1X7" device="" package3d_urn="urn:adsk.eagle:package:22477/2"/>
<part name="IC2" library="ADG732BSUZ-REEL" deviceset="ADG732BSUZ-REEL" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="JP1" gate="A" x="139.7" y="-10.16" smashed="yes" grouprefs="BREAKOUT">
<attribute name="NAME" x="133.35" y="3.175" size="1.778" layer="95"/>
<attribute name="VALUE" x="133.35" y="-22.86" size="1.778" layer="96"/>
</instance>
<instance part="JP2" gate="A" x="139.7" y="-40.64" smashed="yes" grouprefs="BREAKOUT">
<attribute name="NAME" x="133.35" y="-27.305" size="1.778" layer="95"/>
<attribute name="VALUE" x="133.35" y="-53.34" size="1.778" layer="96"/>
</instance>
<instance part="JP4" gate="A" x="139.7" y="-106.68" smashed="yes" grouprefs="BREAKOUT">
<attribute name="NAME" x="133.35" y="-93.345" size="1.778" layer="95"/>
<attribute name="VALUE" x="133.35" y="-124.46" size="1.778" layer="96"/>
</instance>
<instance part="JP3" gate="A" x="139.7" y="-71.12" smashed="yes" grouprefs="BREAKOUT">
<attribute name="NAME" x="133.35" y="-57.785" size="1.778" layer="95"/>
<attribute name="VALUE" x="133.35" y="-83.82" size="1.778" layer="96"/>
</instance>
<instance part="JP5" gate="A" x="167.64" y="-7.62" smashed="yes">
<attribute name="NAME" x="161.29" y="3.175" size="1.778" layer="95"/>
<attribute name="VALUE" x="161.29" y="-20.32" size="1.778" layer="96"/>
</instance>
<instance part="IC2" gate="G$1" x="40.64" y="76.2" smashed="yes">
<attribute name="NAME" x="80.01" y="93.98" size="1.778" layer="95" align="center-left"/>
<attribute name="VALUE" x="80.01" y="91.44" size="1.778" layer="96" align="center-left"/>
</instance>
</instances>
<busses>
</busses>
<nets>
<net name="S12" class="0">
<segment>
<wire x1="40.64" y1="76.2" x2="35.56" y2="76.2" width="0.1524" layer="91" grouprefs="IC"/>
<label x="35.56" y="76.2" size="1.778" layer="95" rot="R180" xref="yes" grouprefs="IC"/>
<pinref part="IC2" gate="G$1" pin="S12"/>
</segment>
<segment>
<pinref part="JP2" gate="A" pin="4"/>
<wire x1="137.16" y1="-38.1" x2="129.54" y2="-38.1" width="0.1524" layer="91" grouprefs="BREAKOUT"/>
<label x="129.54" y="-38.1" size="1.778" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="S11" class="0">
<segment>
<wire x1="40.64" y1="73.66" x2="35.56" y2="73.66" width="0.1524" layer="91" grouprefs="IC"/>
<label x="35.56" y="73.66" size="1.778" layer="95" rot="R180" xref="yes" grouprefs="IC"/>
<pinref part="IC2" gate="G$1" pin="S11"/>
</segment>
<segment>
<pinref part="JP2" gate="A" pin="3"/>
<wire x1="137.16" y1="-35.56" x2="129.54" y2="-35.56" width="0.1524" layer="91" grouprefs="BREAKOUT"/>
<label x="129.54" y="-35.56" size="1.778" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="S10" class="0">
<segment>
<wire x1="40.64" y1="71.12" x2="35.56" y2="71.12" width="0.1524" layer="91" grouprefs="IC"/>
<label x="35.56" y="71.12" size="1.778" layer="95" rot="R180" xref="yes" grouprefs="IC"/>
<pinref part="IC2" gate="G$1" pin="S10"/>
</segment>
<segment>
<pinref part="JP2" gate="A" pin="2"/>
<wire x1="137.16" y1="-33.02" x2="129.54" y2="-33.02" width="0.1524" layer="91" grouprefs="BREAKOUT"/>
<label x="129.54" y="-33.02" size="1.778" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="S9" class="0">
<segment>
<wire x1="40.64" y1="68.58" x2="35.56" y2="68.58" width="0.1524" layer="91" grouprefs="IC"/>
<label x="35.56" y="68.58" size="1.778" layer="95" rot="R180" xref="yes" grouprefs="IC"/>
<pinref part="IC2" gate="G$1" pin="S9"/>
</segment>
<segment>
<pinref part="JP2" gate="A" pin="1"/>
<wire x1="137.16" y1="-30.48" x2="129.54" y2="-30.48" width="0.1524" layer="91" grouprefs="BREAKOUT"/>
<label x="129.54" y="-30.48" size="1.778" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="S8" class="0">
<segment>
<wire x1="40.64" y1="66.04" x2="35.56" y2="66.04" width="0.1524" layer="91" grouprefs="IC"/>
<label x="35.56" y="66.04" size="1.778" layer="95" rot="R180" xref="yes" grouprefs="IC"/>
<pinref part="IC2" gate="G$1" pin="S8"/>
</segment>
<segment>
<pinref part="JP1" gate="A" pin="8"/>
<wire x1="137.16" y1="-17.78" x2="129.54" y2="-17.78" width="0.1524" layer="91" grouprefs="BREAKOUT"/>
<label x="129.54" y="-17.78" size="1.778" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="S7" class="0">
<segment>
<wire x1="40.64" y1="63.5" x2="35.56" y2="63.5" width="0.1524" layer="91" grouprefs="IC"/>
<label x="35.56" y="63.5" size="1.778" layer="95" rot="R180" xref="yes" grouprefs="IC"/>
<pinref part="IC2" gate="G$1" pin="S7"/>
</segment>
<segment>
<pinref part="JP1" gate="A" pin="7"/>
<wire x1="137.16" y1="-15.24" x2="129.54" y2="-15.24" width="0.1524" layer="91" grouprefs="BREAKOUT"/>
<label x="129.54" y="-15.24" size="1.778" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="S6" class="0">
<segment>
<wire x1="40.64" y1="60.96" x2="35.56" y2="60.96" width="0.1524" layer="91" grouprefs="IC"/>
<label x="35.56" y="60.96" size="1.778" layer="95" rot="R180" xref="yes" grouprefs="IC"/>
<pinref part="IC2" gate="G$1" pin="S6"/>
</segment>
<segment>
<pinref part="JP1" gate="A" pin="6"/>
<wire x1="137.16" y1="-12.7" x2="129.54" y2="-12.7" width="0.1524" layer="91" grouprefs="BREAKOUT"/>
<label x="129.54" y="-12.7" size="1.778" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="S5" class="0">
<segment>
<wire x1="40.64" y1="58.42" x2="35.56" y2="58.42" width="0.1524" layer="91" grouprefs="IC"/>
<label x="35.56" y="58.42" size="1.778" layer="95" rot="R180" xref="yes" grouprefs="IC"/>
<pinref part="IC2" gate="G$1" pin="S5"/>
</segment>
<segment>
<pinref part="JP1" gate="A" pin="5"/>
<wire x1="137.16" y1="-10.16" x2="129.54" y2="-10.16" width="0.1524" layer="91" grouprefs="BREAKOUT"/>
<label x="129.54" y="-10.16" size="1.778" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="S4" class="0">
<segment>
<wire x1="40.64" y1="55.88" x2="35.56" y2="55.88" width="0.1524" layer="91" grouprefs="IC"/>
<label x="35.56" y="55.88" size="1.778" layer="95" rot="R180" xref="yes" grouprefs="IC"/>
<pinref part="IC2" gate="G$1" pin="S4"/>
</segment>
<segment>
<pinref part="JP1" gate="A" pin="4"/>
<wire x1="137.16" y1="-7.62" x2="129.54" y2="-7.62" width="0.1524" layer="91" grouprefs="BREAKOUT"/>
<label x="129.54" y="-7.62" size="1.778" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="S3" class="0">
<segment>
<wire x1="40.64" y1="53.34" x2="35.56" y2="53.34" width="0.1524" layer="91" grouprefs="IC"/>
<label x="35.56" y="53.34" size="1.778" layer="95" rot="R180" xref="yes" grouprefs="IC"/>
<pinref part="IC2" gate="G$1" pin="S3"/>
</segment>
<segment>
<pinref part="JP1" gate="A" pin="3"/>
<wire x1="137.16" y1="-5.08" x2="129.54" y2="-5.08" width="0.1524" layer="91" grouprefs="BREAKOUT"/>
<label x="129.54" y="-5.08" size="1.778" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="S2" class="0">
<segment>
<wire x1="40.64" y1="50.8" x2="35.56" y2="50.8" width="0.1524" layer="91" grouprefs="IC"/>
<label x="35.56" y="50.8" size="1.778" layer="95" rot="R180" xref="yes" grouprefs="IC"/>
<pinref part="IC2" gate="G$1" pin="S2"/>
</segment>
<segment>
<pinref part="JP1" gate="A" pin="2"/>
<wire x1="137.16" y1="-2.54" x2="129.54" y2="-2.54" width="0.1524" layer="91" grouprefs="BREAKOUT"/>
<label x="129.54" y="-2.54" size="1.778" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="S1" class="0">
<segment>
<wire x1="40.64" y1="48.26" x2="35.56" y2="48.26" width="0.1524" layer="91" grouprefs="IC"/>
<label x="35.56" y="48.26" size="1.778" layer="95" rot="R180" xref="yes" grouprefs="IC"/>
<pinref part="IC2" gate="G$1" pin="S1"/>
</segment>
<segment>
<pinref part="JP1" gate="A" pin="1"/>
<wire x1="137.16" y1="0" x2="129.54" y2="0" width="0.1524" layer="91" grouprefs="BREAKOUT"/>
<label x="129.54" y="0" size="1.778" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="A0" class="0">
<segment>
<wire x1="53.34" y1="30.48" x2="53.34" y2="25.4" width="0.1524" layer="91" grouprefs="IC"/>
<label x="53.34" y="25.4" size="1.778" layer="95" rot="R270" xref="yes" grouprefs="IC"/>
<pinref part="IC2" gate="G$1" pin="A0"/>
</segment>
<segment>
<wire x1="165.1" y1="0" x2="157.48" y2="0" width="0.1524" layer="91" grouprefs="BREAKOUT"/>
<label x="157.48" y="0" size="1.778" layer="95" rot="R180" xref="yes" grouprefs="BREAKOUT"/>
<pinref part="JP5" gate="A" pin="1"/>
</segment>
</net>
<net name="A1" class="0">
<segment>
<wire x1="55.88" y1="30.48" x2="55.88" y2="25.4" width="0.1524" layer="91" grouprefs="IC"/>
<label x="55.88" y="25.4" size="1.778" layer="95" rot="R270" xref="yes" grouprefs="IC"/>
<pinref part="IC2" gate="G$1" pin="A1"/>
</segment>
<segment>
<wire x1="165.1" y1="-2.54" x2="157.48" y2="-2.54" width="0.1524" layer="91" grouprefs="BREAKOUT"/>
<label x="157.48" y="-2.54" size="1.778" layer="95" rot="R180" xref="yes" grouprefs="BREAKOUT"/>
<pinref part="JP5" gate="A" pin="2"/>
</segment>
</net>
<net name="A2" class="0">
<segment>
<wire x1="58.42" y1="30.48" x2="58.42" y2="25.4" width="0.1524" layer="91" grouprefs="IC"/>
<label x="58.42" y="25.4" size="1.778" layer="95" rot="R270" xref="yes" grouprefs="IC"/>
<pinref part="IC2" gate="G$1" pin="A2"/>
</segment>
<segment>
<wire x1="165.1" y1="-5.08" x2="157.48" y2="-5.08" width="0.1524" layer="91" grouprefs="BREAKOUT"/>
<label x="157.48" y="-5.08" size="1.778" layer="95" rot="R180" xref="yes" grouprefs="BREAKOUT"/>
<pinref part="JP5" gate="A" pin="3"/>
</segment>
</net>
<net name="A3" class="0">
<segment>
<wire x1="60.96" y1="30.48" x2="60.96" y2="25.4" width="0.1524" layer="91" grouprefs="IC"/>
<label x="60.96" y="25.4" size="1.778" layer="95" rot="R270" xref="yes" grouprefs="IC"/>
<pinref part="IC2" gate="G$1" pin="A3"/>
</segment>
<segment>
<wire x1="165.1" y1="-7.62" x2="157.48" y2="-7.62" width="0.1524" layer="91" grouprefs="BREAKOUT"/>
<label x="157.48" y="-7.62" size="1.778" layer="95" rot="R180" xref="yes" grouprefs="BREAKOUT"/>
<pinref part="JP5" gate="A" pin="4"/>
</segment>
</net>
<net name="A4" class="0">
<segment>
<wire x1="63.5" y1="30.48" x2="63.5" y2="25.4" width="0.1524" layer="91" grouprefs="IC"/>
<label x="63.5" y="25.4" size="1.778" layer="95" rot="R270" xref="yes" grouprefs="IC"/>
<pinref part="IC2" gate="G$1" pin="A4"/>
</segment>
<segment>
<wire x1="165.1" y1="-10.16" x2="157.48" y2="-10.16" width="0.1524" layer="91" grouprefs="BREAKOUT"/>
<label x="157.48" y="-10.16" size="1.778" layer="95" rot="R180" xref="yes" grouprefs="BREAKOUT"/>
<pinref part="JP5" gate="A" pin="5"/>
</segment>
</net>
<net name="!EN" class="0">
<segment>
<wire x1="71.12" y1="30.48" x2="71.12" y2="25.4" width="0.1524" layer="91" grouprefs="IC"/>
<label x="71.12" y="25.4" size="1.778" layer="95" rot="R270" xref="yes" grouprefs="IC"/>
<pinref part="IC2" gate="G$1" pin="!EN"/>
</segment>
<segment>
<pinref part="JP5" gate="A" pin="7"/>
<wire x1="165.1" y1="-15.24" x2="157.48" y2="-15.24" width="0.1524" layer="91"/>
<label x="157.48" y="-15.24" size="1.778" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="GND" class="0">
<segment>
<pinref part="JP4" gate="A" pin="9"/>
<wire x1="137.16" y1="-116.84" x2="129.54" y2="-116.84" width="0.1524" layer="91" grouprefs="BREAKOUT"/>
<label x="129.54" y="-116.84" size="1.778" layer="95" rot="R180" xref="yes"/>
</segment>
<segment>
<pinref part="IC2" gate="G$1" pin="VSS"/>
<wire x1="76.2" y1="30.48" x2="76.2" y2="25.4" width="0.1524" layer="91" grouprefs="IC"/>
<wire x1="76.2" y1="25.4" x2="73.66" y2="25.4" width="0.1524" layer="91" grouprefs="IC"/>
<pinref part="IC2" gate="G$1" pin="GND"/>
<wire x1="73.66" y1="30.48" x2="73.66" y2="25.4" width="0.1524" layer="91" grouprefs="IC"/>
<label x="73.66" y="25.4" size="1.778" layer="95" rot="R270" xref="yes" grouprefs="IC"/>
</segment>
</net>
<net name="S28" class="0">
<segment>
<wire x1="83.82" y1="76.2" x2="88.9" y2="76.2" width="0.1524" layer="91" grouprefs="IC"/>
<label x="88.9" y="76.2" size="1.778" layer="95" xref="yes" grouprefs="IC"/>
<pinref part="IC2" gate="G$1" pin="S28"/>
</segment>
<segment>
<wire x1="137.16" y1="-104.14" x2="129.54" y2="-104.14" width="0.1524" layer="91" grouprefs="BREAKOUT"/>
<pinref part="JP4" gate="A" pin="4"/>
<label x="129.54" y="-104.14" size="1.778" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="S27" class="0">
<segment>
<wire x1="83.82" y1="73.66" x2="88.9" y2="73.66" width="0.1524" layer="91" grouprefs="IC"/>
<label x="88.9" y="73.66" size="1.778" layer="95" xref="yes" grouprefs="IC"/>
<pinref part="IC2" gate="G$1" pin="S27"/>
</segment>
<segment>
<wire x1="137.16" y1="-101.6" x2="129.54" y2="-101.6" width="0.1524" layer="91" grouprefs="BREAKOUT"/>
<pinref part="JP4" gate="A" pin="3"/>
<label x="129.54" y="-101.6" size="1.778" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="S26" class="0">
<segment>
<wire x1="83.82" y1="71.12" x2="88.9" y2="71.12" width="0.1524" layer="91" grouprefs="IC"/>
<label x="88.9" y="71.12" size="1.778" layer="95" xref="yes" grouprefs="IC"/>
<pinref part="IC2" gate="G$1" pin="S26"/>
</segment>
<segment>
<wire x1="137.16" y1="-99.06" x2="129.54" y2="-99.06" width="0.1524" layer="91" grouprefs="BREAKOUT"/>
<label x="129.54" y="-99.06" size="1.778" layer="95" rot="R180" xref="yes"/>
<pinref part="JP4" gate="A" pin="2"/>
</segment>
</net>
<net name="S25" class="0">
<segment>
<wire x1="83.82" y1="68.58" x2="88.9" y2="68.58" width="0.1524" layer="91" grouprefs="IC"/>
<label x="88.9" y="68.58" size="1.778" layer="95" xref="yes" grouprefs="IC"/>
<pinref part="IC2" gate="G$1" pin="S25"/>
</segment>
<segment>
<wire x1="137.16" y1="-96.52" x2="129.54" y2="-96.52" width="0.1524" layer="91" grouprefs="BREAKOUT"/>
<label x="129.54" y="-96.52" size="1.778" layer="95" rot="R180" xref="yes"/>
<pinref part="JP4" gate="A" pin="1"/>
</segment>
</net>
<net name="S24" class="0">
<segment>
<wire x1="83.82" y1="66.04" x2="88.9" y2="66.04" width="0.1524" layer="91" grouprefs="IC"/>
<label x="88.9" y="66.04" size="1.778" layer="95" xref="yes" grouprefs="IC"/>
<pinref part="IC2" gate="G$1" pin="S24"/>
</segment>
<segment>
<wire x1="137.16" y1="-78.74" x2="129.54" y2="-78.74" width="0.1524" layer="91" grouprefs="BREAKOUT"/>
<label x="129.54" y="-78.74" size="1.778" layer="95" rot="R180" xref="yes"/>
<pinref part="JP3" gate="A" pin="8"/>
</segment>
</net>
<net name="S23" class="0">
<segment>
<wire x1="83.82" y1="63.5" x2="88.9" y2="63.5" width="0.1524" layer="91" grouprefs="IC"/>
<label x="88.9" y="63.5" size="1.778" layer="95" xref="yes" grouprefs="IC"/>
<pinref part="IC2" gate="G$1" pin="S23"/>
</segment>
<segment>
<wire x1="137.16" y1="-76.2" x2="129.54" y2="-76.2" width="0.1524" layer="91" grouprefs="BREAKOUT"/>
<label x="129.54" y="-76.2" size="1.778" layer="95" rot="R180" xref="yes"/>
<pinref part="JP3" gate="A" pin="7"/>
</segment>
</net>
<net name="S22" class="0">
<segment>
<wire x1="83.82" y1="60.96" x2="88.9" y2="60.96" width="0.1524" layer="91" grouprefs="IC"/>
<label x="88.9" y="60.96" size="1.778" layer="95" xref="yes" grouprefs="IC"/>
<pinref part="IC2" gate="G$1" pin="S22"/>
</segment>
<segment>
<wire x1="137.16" y1="-73.66" x2="129.54" y2="-73.66" width="0.1524" layer="91" grouprefs="BREAKOUT"/>
<label x="129.54" y="-73.66" size="1.778" layer="95" rot="R180" xref="yes"/>
<pinref part="JP3" gate="A" pin="6"/>
</segment>
</net>
<net name="S21" class="0">
<segment>
<wire x1="83.82" y1="58.42" x2="88.9" y2="58.42" width="0.1524" layer="91" grouprefs="IC"/>
<label x="88.9" y="58.42" size="1.778" layer="95" xref="yes" grouprefs="IC"/>
<pinref part="IC2" gate="G$1" pin="S21"/>
</segment>
<segment>
<wire x1="137.16" y1="-71.12" x2="129.54" y2="-71.12" width="0.1524" layer="91" grouprefs="BREAKOUT"/>
<label x="129.54" y="-71.12" size="1.778" layer="95" rot="R180" xref="yes"/>
<pinref part="JP3" gate="A" pin="5"/>
</segment>
</net>
<net name="S20" class="0">
<segment>
<wire x1="83.82" y1="55.88" x2="88.9" y2="55.88" width="0.1524" layer="91" grouprefs="IC"/>
<label x="88.9" y="55.88" size="1.778" layer="95" xref="yes" grouprefs="IC"/>
<pinref part="IC2" gate="G$1" pin="S20"/>
</segment>
<segment>
<wire x1="137.16" y1="-68.58" x2="129.54" y2="-68.58" width="0.1524" layer="91" grouprefs="BREAKOUT"/>
<label x="129.54" y="-68.58" size="1.778" layer="95" rot="R180" xref="yes"/>
<pinref part="JP3" gate="A" pin="4"/>
</segment>
</net>
<net name="S19" class="0">
<segment>
<wire x1="83.82" y1="53.34" x2="88.9" y2="53.34" width="0.1524" layer="91" grouprefs="IC"/>
<label x="88.9" y="53.34" size="1.778" layer="95" xref="yes" grouprefs="IC"/>
<pinref part="IC2" gate="G$1" pin="S19"/>
</segment>
<segment>
<wire x1="137.16" y1="-66.04" x2="129.54" y2="-66.04" width="0.1524" layer="91" grouprefs="BREAKOUT"/>
<label x="129.54" y="-66.04" size="1.778" layer="95" rot="R180" xref="yes"/>
<pinref part="JP3" gate="A" pin="3"/>
</segment>
</net>
<net name="S18" class="0">
<segment>
<wire x1="83.82" y1="50.8" x2="88.9" y2="50.8" width="0.1524" layer="91" grouprefs="IC"/>
<label x="88.9" y="50.8" size="1.778" layer="95" xref="yes" grouprefs="IC"/>
<pinref part="IC2" gate="G$1" pin="S18"/>
</segment>
<segment>
<wire x1="137.16" y1="-63.5" x2="129.54" y2="-63.5" width="0.1524" layer="91" grouprefs="BREAKOUT"/>
<label x="129.54" y="-63.5" size="1.778" layer="95" rot="R180" xref="yes"/>
<pinref part="JP3" gate="A" pin="2"/>
</segment>
</net>
<net name="S17" class="0">
<segment>
<wire x1="83.82" y1="48.26" x2="88.9" y2="48.26" width="0.1524" layer="91" grouprefs="IC"/>
<label x="88.9" y="48.26" size="1.778" layer="95" xref="yes" grouprefs="IC"/>
<pinref part="IC2" gate="G$1" pin="S17"/>
</segment>
<segment>
<wire x1="137.16" y1="-60.96" x2="129.54" y2="-60.96" width="0.1524" layer="91" grouprefs="BREAKOUT"/>
<label x="129.54" y="-60.96" size="1.778" layer="95" rot="R180" xref="yes"/>
<pinref part="JP3" gate="A" pin="1"/>
</segment>
</net>
<net name="S13" class="0">
<segment>
<wire x1="48.26" y1="93.98" x2="48.26" y2="99.06" width="0.1524" layer="91" grouprefs="IC"/>
<label x="48.26" y="99.06" size="1.778" layer="95" rot="R90" xref="yes" grouprefs="IC"/>
<pinref part="IC2" gate="G$1" pin="S13"/>
</segment>
<segment>
<pinref part="JP2" gate="A" pin="5"/>
<wire x1="137.16" y1="-40.64" x2="129.54" y2="-40.64" width="0.1524" layer="91" grouprefs="BREAKOUT"/>
<label x="129.54" y="-40.64" size="1.778" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="S14" class="0">
<segment>
<wire x1="50.8" y1="93.98" x2="50.8" y2="99.06" width="0.1524" layer="91" grouprefs="IC"/>
<label x="50.8" y="99.06" size="1.778" layer="95" rot="R90" xref="yes" grouprefs="IC"/>
<pinref part="IC2" gate="G$1" pin="S14"/>
</segment>
<segment>
<pinref part="JP2" gate="A" pin="6"/>
<wire x1="137.16" y1="-43.18" x2="129.54" y2="-43.18" width="0.1524" layer="91" grouprefs="BREAKOUT"/>
<label x="129.54" y="-43.18" size="1.778" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="S15" class="0">
<segment>
<wire x1="53.34" y1="93.98" x2="53.34" y2="99.06" width="0.1524" layer="91" grouprefs="IC"/>
<label x="53.34" y="99.06" size="1.778" layer="95" rot="R90" xref="yes" grouprefs="IC"/>
<pinref part="IC2" gate="G$1" pin="S15"/>
</segment>
<segment>
<pinref part="JP2" gate="A" pin="7"/>
<wire x1="137.16" y1="-45.72" x2="129.54" y2="-45.72" width="0.1524" layer="91" grouprefs="BREAKOUT"/>
<label x="129.54" y="-45.72" size="1.778" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="S16" class="0">
<segment>
<wire x1="55.88" y1="93.98" x2="55.88" y2="99.06" width="0.1524" layer="91" grouprefs="IC"/>
<label x="55.88" y="99.06" size="1.778" layer="95" rot="R90" xref="yes" grouprefs="IC"/>
<pinref part="IC2" gate="G$1" pin="S16"/>
</segment>
<segment>
<pinref part="JP2" gate="A" pin="8"/>
<wire x1="137.16" y1="-48.26" x2="129.54" y2="-48.26" width="0.1524" layer="91" grouprefs="BREAKOUT"/>
<label x="129.54" y="-48.26" size="1.778" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="NC_3" class="0">
<segment>
<wire x1="58.42" y1="93.98" x2="58.42" y2="99.06" width="0.1524" layer="91" grouprefs="IC"/>
<label x="58.42" y="99.06" size="1.778" layer="95" rot="R90" xref="yes" grouprefs="IC"/>
<pinref part="IC2" gate="G$1" pin="NIC_3"/>
</segment>
</net>
<net name="D" class="0">
<segment>
<wire x1="60.96" y1="93.98" x2="60.96" y2="99.06" width="0.1524" layer="91" grouprefs="IC"/>
<label x="60.96" y="99.06" size="1.778" layer="95" rot="R90" xref="yes" grouprefs="IC"/>
<pinref part="IC2" gate="G$1" pin="D"/>
</segment>
<segment>
<pinref part="JP5" gate="A" pin="6"/>
<wire x1="165.1" y1="-12.7" x2="157.48" y2="-12.7" width="0.1524" layer="91"/>
<label x="157.48" y="-12.7" size="1.778" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="NC_2" class="0">
<segment>
<wire x1="63.5" y1="93.98" x2="63.5" y2="99.06" width="0.1524" layer="91" grouprefs="IC"/>
<label x="63.5" y="99.06" size="1.778" layer="95" rot="R90" xref="yes" grouprefs="IC"/>
<pinref part="IC2" gate="G$1" pin="NIC_2"/>
</segment>
</net>
<net name="NC_1" class="0">
<segment>
<wire x1="66.04" y1="93.98" x2="66.04" y2="99.06" width="0.1524" layer="91" grouprefs="IC"/>
<label x="66.04" y="99.06" size="1.778" layer="95" rot="R90" xref="yes" grouprefs="IC"/>
<pinref part="IC2" gate="G$1" pin="NIC_1"/>
</segment>
</net>
<net name="S32" class="0">
<segment>
<wire x1="137.16" y1="-114.3" x2="129.54" y2="-114.3" width="0.1524" layer="91" grouprefs="BREAKOUT"/>
<pinref part="JP4" gate="A" pin="8"/>
<label x="129.54" y="-114.3" size="1.778" layer="95" rot="R180" xref="yes"/>
</segment>
<segment>
<pinref part="IC2" gate="G$1" pin="!WR"/>
<wire x1="68.58" y1="30.48" x2="68.58" y2="25.4" width="0.1524" layer="91"/>
<label x="68.58" y="25.4" size="1.778" layer="95" rot="R270" xref="yes"/>
</segment>
</net>
<net name="S31" class="0">
<segment>
<wire x1="137.16" y1="-111.76" x2="129.54" y2="-111.76" width="0.1524" layer="91" grouprefs="BREAKOUT"/>
<pinref part="JP4" gate="A" pin="7"/>
<label x="129.54" y="-111.76" size="1.778" layer="95" rot="R180" xref="yes"/>
</segment>
<segment>
<pinref part="IC2" gate="G$1" pin="!CS"/>
<wire x1="66.04" y1="30.48" x2="66.04" y2="25.4" width="0.1524" layer="91"/>
<label x="66.04" y="25.4" size="1.778" layer="95" rot="R270" xref="yes"/>
</segment>
</net>
<net name="S30" class="0">
<segment>
<wire x1="73.66" y1="93.98" x2="73.66" y2="99.06" width="0.1524" layer="91" grouprefs="IC"/>
<label x="73.66" y="99.06" size="1.778" layer="95" rot="R90" xref="yes" grouprefs="IC"/>
<pinref part="IC2" gate="G$1" pin="S30"/>
</segment>
<segment>
<wire x1="137.16" y1="-109.22" x2="129.54" y2="-109.22" width="0.1524" layer="91" grouprefs="BREAKOUT"/>
<pinref part="JP4" gate="A" pin="6"/>
<label x="129.54" y="-109.22" size="1.778" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="S29" class="0">
<segment>
<wire x1="76.2" y1="93.98" x2="76.2" y2="99.06" width="0.1524" layer="91" grouprefs="IC"/>
<label x="76.2" y="99.06" size="1.778" layer="95" rot="R90" xref="yes" grouprefs="IC"/>
<pinref part="IC2" gate="G$1" pin="S29"/>
</segment>
<segment>
<wire x1="137.16" y1="-106.68" x2="129.54" y2="-106.68" width="0.1524" layer="91" grouprefs="BREAKOUT"/>
<pinref part="JP4" gate="A" pin="5"/>
<label x="129.54" y="-106.68" size="1.778" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="VDD_2" class="0">
<segment>
<wire x1="50.8" y1="30.48" x2="50.8" y2="25.4" width="0.1524" layer="91" grouprefs="IC"/>
<wire x1="50.8" y1="25.4" x2="48.26" y2="25.4" width="0.1524" layer="91" grouprefs="IC"/>
<wire x1="48.26" y1="30.48" x2="48.26" y2="25.4" width="0.1524" layer="91" grouprefs="IC"/>
<wire x1="48.26" y1="25.4" x2="48.26" y2="-119.38" width="0.1524" layer="91" grouprefs="IC"/>
<wire x1="48.26" y1="-119.38" x2="137.16" y2="-119.38" width="0.1524" layer="91" grouprefs="BREAKOUT"/>
<pinref part="JP4" gate="A" pin="10"/>
<junction x="48.26" y="25.4" grouprefs="IC"/>
<pinref part="IC2" gate="G$1" pin="VDD_1"/>
<pinref part="IC2" gate="G$1" pin="VDD_2"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
<compatibility>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports URNs for individual library
assets (packages, symbols, and devices). The URNs of those assets
will not be understood (or retained) with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports the association of 3D packages
with devices in libraries, schematics, and board files. Those 3D
packages will not be understood (or retained) with this version.
</note>
<note version="9.5" severity="warning">
Since Version 9.5, EAGLE supports persistent groups with
schematics, and board files. Those persistent groups
will not be understood (or retained) with this version.
</note>
</compatibility>
</eagle>
