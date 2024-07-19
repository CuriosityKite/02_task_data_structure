#include "XML.h"

int main()
{
	Device myDevice("Axis", "P7214", "5.50.2");

	myDevice.addCredentialsRef("creds");

	myDevice.addVideoSourceRef("video_source_for_P7214");
	myDevice.addVideoSourceRef("video_source_for_Pqwewqdewdwqd7214");

	myDevice.addVideoStreamingRef("video_source_for_P7214", "vs_P712", "true");
	myDevice.addDetectorRef("video_source_for_P7214", "motion_detection", "1");
	myDevice.addDetectorRef("video_source_for_P7214", "tampering_detection", "1");

	myDevice.addTelemetryRef("telemetry_P7214");
	myDevice.addAudioSourceRef("as_g711_g726_aac_8-64_positive_gain");
	myDevice.addAudioDestinationRef("ad_g711_g726_output_gain_9_53");
	myDevice.addSerialPortRef("serialPortRef");
	myDevice.addIoDeviceRef("iodev_4x4_configurable");

	myDevice.display();
	Sleep(50000000);
	return 0;
}