<template>
	<popup-layer ref="popupRef" :direction="'top'" v-model="show">
		<view class="popupContainer">
			<view class="popupTitle">
				<p>特药待遇<uni-icons type="closeempty" size="22" @click="close()" class="closePopup"></uni-icons>
				</p>
			</view>
			<view class="baseInfo">
				<uni-forms ref="treatmentInfoForm" :rules="rules" :modelValue="treatmentData">
					<uni-forms-item label="待遇标准" name="name" required>
						<uni-easyinput v-model="treatmentData.name" placeholder="请选择待遇标准" disabled
							@click="selectTreatment" />
					</uni-forms-item>
					<uni-forms-item label="定点医院" name="hospitalName" required>
						<uni-easyinput v-model="treatmentData.hospitalName" disabled placeholder="请选择定点医院"
							@click="selectHospital" />
					</uni-forms-item>
					<uni-forms-item label="责任医生" name="doctorName">
						<fy-picker :range="doctorList" @beforeOpen="beforeOpen" range-key="doctorName"
							@confirm="onconfirmDoc">
							<uni-easyinput v-model="treatmentData.doctorName" disabled placeholder="请选择责任医生" />
						</fy-picker>

					</uni-forms-item>
					<uni-forms-item label="最大待遇报销" name="maxNumber" required>
						<uni-easyinput v-model="treatmentData.maxNumber" placeholder="请输入报销量" />
					</uni-forms-item>
					<uni-forms-item label="待遇开始时间" name="startDate" required>
						<uni-datetime-picker type="date" :clear-icon="false" @change="changeStartDate" :end="treatmentData.endDate"
							v-model="treatmentData.startDate" placeholder="请选择待遇开始时间" />
					</uni-forms-item>
					<uni-forms-item label="待遇结束时间" name="endDate" required>
						<uni-datetime-picker type="date" :clear-icon="false" :start="treatmentData.startDate"
							v-model="treatmentData.endDate" placeholder="请选择待遇结束时间" />
					</uni-forms-item>
					<uni-forms-item label="报销年度" name="year">
						<uni-easyinput v-model="treatmentData.year" placeholder="请输入报销年度" />
					</uni-forms-item>
					<uni-forms-item label="备注" name="remark">
						<uni-easyinput type="textarea" v-model="treatmentData.remark" placeholder="请输入备注" />
					</uni-forms-item>
					<div style="margin-bottom: 30rpx;" v-for="(item,index) in attachList">
						<uni-file-picker v-model="item.attachVos" style="margin: 10rpx 0;" :limit="1" @select="selectPic($event,index)"
							@delete="deleteFile($event,index)" :key="item.id" :title="item.name"></uni-file-picker>
					</div>
					<button class="appButton mainBtn-color" @click="sendInfo('treatmentInfoForm')">提交</button>
				</uni-forms>
			</view>
		</view>
		<select-hospital :show="selecthospitalShow" @selectHospitalData="selectHospitalData"></select-hospital>
		<select-treatment :show="selectselectTreatmentShow" @selectTreatmentData="selectTreatmentData">
		</select-treatment>
	</popup-layer>
</template>

<script>
	import popupLayer from '@/components/popup-layer/popup-layer.vue';
	import selectHospital from '@/component/selectHospital.vue';
	import selectTreatment from '@/component/selectTreatment.vue';
	export default {
		components: {
			popupLayer,
			selectHospital,
			selectTreatment
		},
		name: "addTreatment",
		props: {
			/**
			 * 输入类型
			 */
			isEdit:{
				type:Boolean,
				default: false
			},
			show: {
				type: Boolean,
				default: false
			},
			data: {
				type: Object,
				default () {
					return {}
				}
			},
			/**
			 * 值
			 */
		},
		watch: {
			show(val) {
				console.log(this.show)
				if (val && !this.data.name) {
					this.treatmentData = {
						treatmentStandardId: "", //待遇标准
						name: "",
						hospitalId: "", //定点医院
						hospitalName: "",
						doctorId: "", //责任医生
						doctorName: "",
						maxNumber: "", //最大报销量
						expire: "",
						startDate: "", //待遇开始时间
						endDate: "", //待遇结束时间
						year: "", //报销年度
						remark: "", //备注
						attachList: [],
						attachInfo: []
					};
					this.attachList=[];
				} else {
					
					this.treatmentData = JSON.parse(JSON.stringify(this.data));
					this.attachList = JSON.parse(JSON.stringify(this.data.attachList));
					var that = this;
					if(this.treatmentData.attachsPrefix){
						that.attachList.forEach(function(item){
							item.attachVos.forEach( function(val){ 
								if (that.changeAttachs) {
									if(!val.fileName){
										val.fileName = val.url;
									}
									val.originalFileName = val.name;
									val.url = '';
									val.url = that.treatmentData.attachsPrefix + val.fileName;
									val.extname = val.name;
								}
							})
						})
					}
					console.log(this.attachList)
				}
			},
			
		},

		data() {
			return {
				treatmentData: this.data,
				hospitalList: [],
				// 控制医院控件展示
				selecthospitalShow: false,
				// 控制特药待遇控件展示
				selectselectTreatmentShow: false,
				// 医生列表
				doctorList: [],
				// 上传列表
				attachList: [],
				changeAttachs: true,
				rules: {
					name: {
						rules: [{
							required: true,
							errorMessage: '待遇名称不能为空'
						}]
					},
					hospitalName: {
						rules: [{
							required: true,
							errorMessage: '医院不能为空'
						}]
					},
					startDate: {
						rules: [{
							required: true,
							errorMessage: '开始时间不能为空'
						}]
					},
					endDate: {
						rules: [{
							required: true,
							errorMessage: '结束时间不能为空'
						}]
					},
				}
			};
		},
		created() {

		},

		methods: {
			changeStartDate(val){
				if(this.treatmentData.expire){
					this.treatmentData.endDate=this.dateFormat("YYYY-mm-dd",this.addMonth(new Date(val),this.treatmentData.expire))
				}
			},
			// 关闭组件
			close(event) {
				this.$emit("closeTreatment", false)
			},
			// 医院控件
			selectHospital() {
				this.selecthospitalShow = true
			},
			// 数值返回并填入
			selectHospitalData(val) {
				if (val) {
					this.treatmentData.hospitalName = val.name;
					this.treatmentData.hospitalId = val.id;
				}
				this.selecthospitalShow = false;
				this.getDoctorList(val.id)
			},

			// 待遇组件
			selectTreatment() {
				this.selectselectTreatmentShow = true
			},
			// 数值返回并填入
			selectTreatmentData(val) {
				if (val) {
					this.treatmentData.name = val.name
					this.treatmentData.maxNumber = val.maxNumber;
					this.treatmentData.expire = val.expire;
					this.treatmentData.treatmentStandardId = val.id
				}
				this.selectselectTreatmentShow = false
				this.getAttachList(val.id)
			},
			// 判断医生数据
			beforeOpen() {
				this.$showModal({
					content: '无医生数据！',
					showCancel: false
				});
			},
			// 确认医生选择
			onconfirmDoc(val) {
				this.treatmentData.doctorName = val.text;
				this.treatmentData.doctorId = val.selected[0].id;
			},

			/******** 信息获取函数 **********/

			// 获取医生列表
			getDoctorList(id) {
				let params = {
					hospitalId: id
				};
				this.$api
					.getDoctorList(params)
					.then(res => {
						this.doctorList = res.doctorList
					})
					.catch(err => {});
			},
			// 获取上传列表
			getAttachList(id) {
				let params = {
					standardId: id,
					type: 1
				}
				this.$api
					.getAttachList(params)
					.then(res => {
						this.attachList = res.attaches
						this.attachList.forEach((item, index) => {
							item.attachVos = []
						})
					})
					.catch(err => {})
			},

			// 图片上传
			selectPic(e, index) {
				console.log(this.attachList);
				// let tempFilePaths = e.tempFilePaths;
				// const uploadTask = uni.uploadFile({
				// 	url: 'http://119.3.158.96:8780/file-server/file/uploadFile', //仅为示例，非真实的接口地址
				// 	filePath: tempFilePaths[0],
				// 	name: 'file',
				// 	header: {
				// 		"Content-Type": "multipart/form-data"
				// 	},
				// 	complete: (uploadFileRes) => {
				// 		let data = JSON.parse(uploadFileRes.data)
				// 		console.log(this.attachList);
				// 		this.attachList[index].attachVos.push({
				// 			"name": data.fileName,
				// 			"extname": data.fileName,
				// 			"url":data.data.src,
				// 			'fileName': data.fileName,
				// 			'originalFileName': data.originalFileName
				// 		})
				// 		console.log(this.attachList);
				// 		// Vue.set(this.attachList[index].attachVos,this.attachList[index].attachVos.length, {
				// 		// 	"name": data.fileName,
				// 		// 	"extname": data.fileName,
				// 		// 	"url":"https://xxxx",
				// 		// 	'fileName': data.fileName,
				// 		// 	'originalFileName': data.originalFileName
				// 		// })
				// 	}
				// });
			},
			deleteFile(e, index) {
				let i = e.index;
				this.attachList[index].attachVos.splice(i, 1)
				this.changeAttachs = false
				console.log(this.attachList)
			},
			onconfirmTreatment(e) {
				this.treatmentData.treatmentName = e.text
				this.treatmentData.treatment = e.selected.id
			},
			
			// 提交
			sendInfo(ref) {
				this.$refs[ref].validate().then(res => {
					uni.showToast({
						title: `添加成功！`
					})
					var attachInfo = [];
					this.attachList.forEach(function(item, index) {
						item.attachVos.forEach(function(val, index) {
							attachInfo.push({
								secondBusinessId: item.id,
								url: val.fileName,
								name: val.originalFileName,
								fileName:val.originalFileName,
								originalFileName:val.originalFileName
							})
						})
					})
					
					let attachData = this.attachList.map(function(item, index, arr) {
						return {
							id: item.id,
							name: item.name,
							pic: item.attachVos.map(function(v, i, arr) {
								return v.originalFileName
							}).join(',')
						}
					})
					this.treatmentData.attachList = this.attachList
					this.treatmentData.attachData = attachData
					this.treatmentData.attachInfo = attachInfo
					console.log(this.attachList)
					console.log(this.treatmentData)
					this.$emit("closeTreatment", false)
					this.$emit("treatmentData", this.treatmentData)
				}).catch(err => {})
			
			},

			addMonth(date, addMonth) {
				var y = date.getFullYear();
				var m = date.getMonth();
				var nextY = y;
				var nextM = m;
				//如果当前月+增加的月>11 这里之所以用11是因为 js的月份从0开始
				if ((m + addMonth) > 11) {
					nextY = y + 1;
					nextM = parseInt(m + addMonth) - 12;
				} else {
					nextM = date.getMonth() + addMonth
				}
				var daysInNextMonth = this.daysInMonth(nextY, nextM);
				var day = date.getDate();
				if (day > daysInNextMonth) {
					day = daysInNextMonth;
				}
				return new Date(nextY, nextM, day);
			},
			daysInMonth: function(year, month) {
				if (month == 1) {
					if (year % 4 == 0 && year % 100 != 0)
						return 29;
					else
						return 28;
				} else if ((month <= 6 && month % 2 == 0) || (month = 6 && month % 2 == 1))
					return 31;
				else
					return 30;
			},
			dateFormat(fmt, date) { //时间格式化
				let ret;
				const opt = {
					"Y+": date.getFullYear().toString(), // 年
					"m+": (date.getMonth() + 1).toString(), // 月
					"d+": date.getDate().toString(), // 日
					"H+": date.getHours().toString(), // 时
					"M+": date.getMinutes().toString(), // 分
					"S+": date.getSeconds().toString() // 秒
					// 有其他格式化字符需求可以继续添加，必须转化成字符串
				};
				for (let k in opt) {
					ret = new RegExp("(" + k + ")").exec(fmt);
					if (ret) {
						fmt = fmt.replace(ret[1], (ret[1].length == 1) ? (opt[k]) : (opt[k].padStart(ret[1].length, "0")))
					}
				}
				return fmt;
			},
		}
	}
</script>

<style>
	.popupContainer {
		height: 100vh;
		background-color: #FFFFFF;
		overflow: auto;
	}

	.popupTitle {
		position: relative;
		text-align: center;
		width: 100%;
	}

	.popupTitle p {
		font-size: 20px;
		font-weight: bold;
	}

	.popupTitle .closePopup {
		position: absolute;
		right: 0;
		margin-right: 40rpx;
	}
</style>
