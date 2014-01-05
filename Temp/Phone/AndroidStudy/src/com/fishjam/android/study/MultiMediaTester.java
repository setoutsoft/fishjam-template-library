package com.fishjam.android.study;
import android.test.AndroidTestCase;

/***************************************************************************************************************************************
 * AudioManager
 * 
 * Android �Գ���ý���ʽ�ṩ��֧�֣�
 *   ͼƬ��JPEG, GIF, PNG, BMP ��
 *   ��Ƶ��3GP, MP3, WAV ��
 *   ��Ƶ��3GP, MP4 ��
 *   
 * ��������Ƶ
 *   MediaPlayer -- ��̬�� create ��������ʵ����Ȼ���ͨ�� start/pause/stop �ȷ�������
 *     setDataSrouce -- ������Ҫ�����ļ���·��
 *     prepare -- ��startǰ����
 *     OnCompletionListener -- ��ý�岥�����ʱ��ص��Ľӿڣ����� onCompletion ������ͨ�� setOnCompletionListener ����
 *   JetPlayer
 * VideoView + MediaController -- �ɺ����׵�ʵ����Ƶ������
 *   video.setMediaController �� ctrl.setMediaPlayer �໥������ Ȼ�� video.requestFocus ��ý���
 *   
 * ¼������Ƶ
 *   MediaRecorder 
 *     setAudioSource -- ������ƵԴ���� AudioSource.MIC
 *     setOutputFormat -- ���������ʽ���� OutputFormat.THREEE_GPP
 *     setAudioEncoder -- ������Ƶ���������� AudioEncoder.AMR_NB
 *     setOutputFile -- ��������ļ�·��
 *     
 * �ֻ�����
 *   Camera -- ����࣬ʵ�����չ���
 *     PictureCallback -- �ڲ��ӿڣ�������Ƭ׼���ú�Ļص�
 *       onPictureTaken() -- ��Ƭ�ص�����ͨ�� AsnycTask ��������첽����
 *     open() -- �����
 *     release() -- �ͷŷ��й���Դ, ������ SurfaceHolder.Callback.surfaceDestroyed �е��ã�ע���� stopPreview
 *     setPreviewDisplay(SurfaceHolder) -- ����Ԥ���������� SurfaceHolder.Callback.surfaceCreated �е���
 *     setParameters() -> startPreview() -- ���ò��������Ԥ���������� SurfaceHolder.Callback.surfaceChanged �е���
 *     takePicture() -- ��������
 *   SurfaceView -- ʵ����ƬԤ������ͼ���
 *   SurfaceHolder -- ������ƽӿڣ�һ��ͨ�� SurfaceView.getHolder ��ã��������ƽ���ĳߴ硢��ʽ�����أ�����ؽ���ߴ�ĸı��
 *     Callback -- �ڲ��ص��ӿڣ��ɻ�ý���ı���Ϣ(surfaceCreated, surfaceChanged, surfaceDestroyed )��ͨ�� addCallback ����
 *     setType() -- �������ͣ��� SurfaceHolder.SURFACE_TYPE_PUSH_BUFFERS
 *     
 * 2Dͼ�δ���  -- android.graphics, android.view.animation �Ȱ���
 *   ͼƬ: Drawable / Bitmap / BitmapFactory
 *     Drawable -- ����ͼƬ�����ж������: BitmapDrawable/ColorDrawable/ShapeDrawable
 *       ʹ�÷�ʽ:
 *         1.�����ڹ����е�ͼƬ�ļ�, �� ImageView.setImageResource(R.drawable.myImage); 
 *         2.XML�ļ�����Drawable����, �� <ImageView android:id=��@id/ImageView01" android:src="@drawable/myimage" ... />
 *         3.ֱ�ӹ���ʵ����ȡ(SD) 
 *           a.Bitmap bmp = BitmapFactory.decodeFile("/sdcard/test.jpg"); ���Ƶ��� decodeResource
 *           b.Bitmap bmp2 = Bitmap.createBitmap(bmp, ...);  //����ԭʼλͼ��������ͼ  
 *           
 *   
 *   ���� -- Animation(���������࣬�ж������) 
 *       AnimationSet -- ���嶯�����Լ�����
 *       AnimationUtils -- ����������
 *     1.Tween -- ����ʹ��ͼ����ƶ����Ŵ���С����ת����͸���ȵȱ仯��
 *       ScaleAnimation/AlphaAnimation/RotateAnimation/TranslateAnimation
 *       ʹ�÷�ʽ:
 *         1.Ӳ���� -- ����Animation����ʵ�������úò�����ͨ�� ImageView.startAnimation �Ⱥ�������ָ������
 *         2.�����ļ�(�Ƽ�) -- res\anim\ Ŀ¼�����ö����ļ���Ȼ��ͨ�� AnimationUtils.loadAnimation ������ö���ʵ������ͨ������� startAnimation ��ʼ��
 *           <set> <alpha android:fromAlpha="0.1" toAlpha="1.0" duration="3000" /></set>�� ���Ƶ��� <scale>, <translate>, <rotate> ��
 *     2.Frame -- ֡������ͨ��˳�򲥷����кõ�ͼƬ��ʵ�֣����Ƶ�Ӱ��
 *       AnimationDrawable -- һ��ͨ��XML�����ļ����ã�<animation-list> <item/></animation-list>��Ȼ����Activity��xml�����п���ͨ�� android:background ָ����
 *  
 * �Ի�
 *   �� View/SurfaceView ����̳У�Ȼ������ onDraw ���� { }��ʹ��Canvas���л��ƣ�ͨ�� postInvalidate �������
 *   Canvas -- ����
 *   Color/Paint(����)/Path/ShapeDrawable�������࣬�� OvalShape(��Բ)��RectShape(����)
 *   
 *   Matrix -- ͼ����Ч������ʵ��ͼ�ε� ��ת(setRotate)������(setScale)��ƽ��(setTranslate)��
 *   Shader -- ��ȾЧ�����кܶ����࣬�� BitmapShader(λͼ��Ⱦ)��ComposeShader(�����Ⱦ)��LinearGradient(������Ⱦ)��
 *      RadialGradient(������Ⱦ), SweepGradient(�ݶ���Ⱦ) �ȣ� ��ͨ�� Paint.setShader(); �ȷ�ʽ��ʹ��
 * 3Dͼ�δ���(OpenGL ES) -- λ�� javax.microedition.khronos.opengles, android.opengl �Ȱ���
 *   
 ***************************************************************************************************************************************/

/***************************************************************************************************************************************
 * ѹ��ͼƬ������ͼ(��MediaStore�в���ͼƬ����)
 *   Uri uri = getContentResolver().insert(Media.EXTERNAL_CONTENT_URI, values); 
 *   Bitmap sourceBmp = BitmapFactory.decodeFile("�ļ�ȫ·��.jpg");             //���Bitmapʵ��
 *   OutputStream outStream = getContentResolver().openOutputStream(uri);  //��������
 *   sourceBmp.compress(Bitmap.CompressFormat.JPEG, 50, outStream);      //ѹ������� 
 *   outStream.close();
***************************************************************************************************************************************/

public class MultiMediaTester extends AndroidTestCase {
	public void test()
	{

	}
}